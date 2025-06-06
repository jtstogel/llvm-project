//===-- llvm/CodeGen/DebugHandlerBase.h -----------------------*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Common functionality for different debug information format backends.
// LLVM currently supports DWARF and CodeView.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CODEGEN_DEBUGHANDLERBASE_H
#define LLVM_CODEGEN_DEBUGHANDLERBASE_H

#include "llvm/CodeGen/AsmPrinterHandler.h"
#include "llvm/CodeGen/DbgEntityHistoryCalculator.h"
#include "llvm/CodeGen/LexicalScopes.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/DebugLoc.h"
#include <optional>

namespace llvm {

class AsmPrinter;
class MachineInstr;
class MachineModuleInfo;

/// Represents the location at which a variable is stored.
struct DbgVariableLocation {
  /// Base register.
  MCRegister Register;

  /// Chain of offsetted loads necessary to load the value if it lives in
  /// memory. Every load except for the last is pointer-sized.
  SmallVector<int64_t, 1> LoadChain;

  /// Present if the location is part of a larger variable.
  std::optional<llvm::DIExpression::FragmentInfo> FragmentInfo;

  /// Extract a VariableLocation from a MachineInstr.
  /// This will only work if Instruction is a debug value instruction
  /// and the associated DIExpression is in one of the supported forms.
  /// If these requirements are not met, the returned Optional will not
  /// have a value.
  static std::optional<DbgVariableLocation>
  extractFromMachineInstruction(const MachineInstr &Instruction);
};

/// Base class for debug information backends. Common functionality related to
/// tracking which variables and scopes are alive at a given PC live here.
class DebugHandlerBase : public AsmPrinterHandler {
protected:
  DebugHandlerBase(AsmPrinter *A);

  /// Target of debug info emission.
  AsmPrinter *Asm = nullptr;

  /// Collected machine module information.
  MachineModuleInfo *MMI = nullptr;

  /// Previous instruction's location information. This is used to
  /// determine label location to indicate scope boundaries in debug info.
  /// We track the previous instruction's source location (if not line 0),
  /// whether it was a label, and its parent BB.
  DebugLoc PrevInstLoc;
  MCSymbol *PrevLabel = nullptr;
  const MachineBasicBlock *PrevInstBB = nullptr;

  /// This location indicates end of function prologue and beginning of
  /// function body.
  const MachineInstr *PrologEndLoc;

  /// This block includes epilogue instructions.
  const MachineBasicBlock *EpilogBeginBlock = nullptr;

  /// If nonnull, stores the current machine instruction we're processing.
  const MachineInstr *CurMI = nullptr;

  LexicalScopes LScopes;

  /// History of DBG_VALUE and clobber instructions for each user
  /// variable.  Variables are listed in order of appearance.
  DbgValueHistoryMap DbgValues;

  /// Mapping of inlined labels and DBG_LABEL machine instruction.
  DbgLabelInstrMap DbgLabels;

  /// Maps instruction with label emitted before instruction.
  /// FIXME: Make this private from DwarfDebug, we have the necessary accessors
  /// for it.
  DenseMap<const MachineInstr *, MCSymbol *> LabelsBeforeInsn;

  /// Maps instruction with label emitted after instruction.
  DenseMap<const MachineInstr *, MCSymbol *> LabelsAfterInsn;

  /// Indentify instructions that are marking the beginning of or
  /// ending of a scope.
  void identifyScopeMarkers();

  /// Ensure that a label will be emitted before MI.
  void requestLabelBeforeInsn(const MachineInstr *MI) {
    LabelsBeforeInsn.try_emplace(MI);
  }

  /// Ensure that a label will be emitted after MI.
  void requestLabelAfterInsn(const MachineInstr *MI) {
    LabelsAfterInsn.try_emplace(MI);
  }

  virtual void beginFunctionImpl(const MachineFunction *MF) = 0;
  virtual void endFunctionImpl(const MachineFunction *MF) = 0;
  virtual void skippedNonDebugFunction() {}

private:
  InstructionOrdering InstOrdering;

  // AsmPrinterHandler overrides.
public:
  virtual ~DebugHandlerBase() override;

  void beginModule(Module *M) override;

  void beginInstruction(const MachineInstr *MI) override;
  void endInstruction() override;

  void beginFunction(const MachineFunction *MF) override;
  void endFunction(const MachineFunction *MF) override;

  void beginBasicBlockSection(const MachineBasicBlock &MBB) override;
  void endBasicBlockSection(const MachineBasicBlock &MBB) override;

  /// Return Label preceding the instruction.
  MCSymbol *getLabelBeforeInsn(const MachineInstr *MI);

  /// Return Label immediately following the instruction.
  MCSymbol *getLabelAfterInsn(const MachineInstr *MI);

  /// If this type is derived from a base type then return base type size.
  static uint64_t getBaseTypeSize(const DIType *Ty);

  /// Return true if type encoding is unsigned.
  static bool isUnsignedDIType(const DIType *Ty);

  const InstructionOrdering &getInstOrdering() const { return InstOrdering; }
};

} // namespace llvm

#endif

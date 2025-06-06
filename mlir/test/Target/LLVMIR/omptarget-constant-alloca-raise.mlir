// RUN: mlir-translate -mlir-to-llvmir %s | FileCheck %s

// A small condensed version of a problem requiring constant alloca raising in
// Target Region Entries for user injected code, found in an issue in the Flang
// compiler. Certain LLVM IR optimisation passes will perform runtime breaking 
// transformations on allocations not found to be in the entry block, current
// OpenMP dialect lowering of TargetOp's will inject user allocations after
// compiler generated entry code, in a separate block, this test checks that
// a small function which attempts to raise some of these (specifically 
// constant sized) allocations performs its task reasonably in these 
// scenarios. 

module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<"dlti.alloca_memory_space", 5 : ui32>>, llvm.target_triple = "amdgcn-amd-amdhsa", omp.is_target_device = true} {
  llvm.func @_QQmain() attributes {omp.declare_target = #omp.declaretarget<device_type = (host), capture_clause = (to)>} {
    %1 = llvm.mlir.constant(1 : i64) : i64
    %2 = llvm.alloca %1 x !llvm.struct<(ptr)> : (i64) -> !llvm.ptr
    %3 = omp.map.info var_ptr(%2 : !llvm.ptr, !llvm.struct<(ptr)>) map_clauses(tofrom) capture(ByRef) -> !llvm.ptr
    omp.target map_entries(%3 -> %arg0 : !llvm.ptr) {
      %4 = llvm.mlir.constant(1 : i32) : i32
      %5 = llvm.alloca %4 x !llvm.struct<(ptr)> {alignment = 8 : i64} : (i32) -> !llvm.ptr<5>
      %ascast1 = llvm.addrspacecast %5 : !llvm.ptr<5> to !llvm.ptr
      %6 = llvm.mlir.constant(50 : i32) : i32
      %7 = llvm.mlir.constant(1 : i64) : i64
      %8 = llvm.alloca %7 x i32 : (i64) -> !llvm.ptr<5>
      %ascast2 = llvm.addrspacecast %8 : !llvm.ptr<5> to !llvm.ptr
      llvm.store %6, %ascast2 : i32, !llvm.ptr
      %9 = llvm.mlir.undef : !llvm.struct<(ptr)>
      %10 = llvm.insertvalue %ascast2, %9[0] : !llvm.struct<(ptr)> 
      llvm.store %10, %ascast1 : !llvm.struct<(ptr)>, !llvm.ptr
      %88 = llvm.call @_ExternalCall(%arg0, %ascast1) : (!llvm.ptr, !llvm.ptr) -> !llvm.struct<()>
      omp.terminator
    }
    llvm.return
  }
  llvm.func @_ExternalCall(!llvm.ptr, !llvm.ptr) -> !llvm.struct<()>
}

// CHECK:      define weak_odr protected amdgpu_kernel void @{{.*}}QQmain_l{{.*}}({{.*}}, {{.*}}) #{{[0-9]+}} {
// CHECK-NEXT: entry:
// CHECK-NEXT:  %[[MOVED_ALLOCA1:.*]] = alloca { ptr }, align 8
// CHECK-NEXT:  %[[MOVED_ALLOCA2:.*]] = alloca i32, i64 1, align 4
// CHECK-NEXT:  %[[MAP_ARG_ALLOCA:.*]] = alloca ptr, align 8

// CHECK: user_code.entry:                                  ; preds = %entry

; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=x86_64-unknown-linux-gnu | FileCheck %s

;; Verify that the machine instructions generated from the first
;; getelementptr don't get sunk below the callbr. (Reduced from a bug
;; report.)

%struct1 = type { ptr, i32 }

define void @klist_dec_and_del(ptr) {
; CHECK-LABEL: klist_dec_and_del:
; CHECK:       # %bb.0:
; CHECK-NEXT:    leaq 8(%rdi), %rax
; CHECK-NEXT:    #APP
; CHECK-NEXT:    # 8(%rdi) .LBB0_1
; CHECK-NEXT:    #NO_APP
; CHECK-NEXT:  # %bb.2:
; CHECK-NEXT:    retq
; CHECK-NEXT:  .LBB0_1: # Inline asm indirect target
; CHECK-NEXT:    # Label of block must be emitted
; CHECK-NEXT:    movq $0, -8(%rax)
; CHECK-NEXT:    retq
  %2 = getelementptr inbounds %struct1, ptr %0, i64 0, i32 1
  callbr void asm sideeffect "# $0 $1", "*m,!i,~{memory},~{dirflag},~{fpsr},~{flags}"(ptr elementtype(i32) %2)
          to label %6 [label %3]

3:
  %4 = getelementptr i32, ptr %2, i64 -2
  %5 = bitcast ptr %4 to ptr
  store ptr null, ptr %5, align 8
  br label %6

6:
  ret void
}

// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_f16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv2i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vfloat16mf4x2_t test_vlsseg2e16_v_f16mf4x2(const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16mf4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_f16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv4i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vfloat16mf2x2_t test_vlsseg2e16_v_f16mf2x2(const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16mf2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_f16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv8i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vfloat16m1x2_t test_vlsseg2e16_v_f16m1x2(const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m1x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_f16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv16i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vfloat16m2x2_t test_vlsseg2e16_v_f16m2x2(const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_f16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv32i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vfloat16m4x2_t test_vlsseg2e16_v_f16m4x2(const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_i16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv2i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vint16mf4x2_t test_vlsseg2e16_v_i16mf4x2(const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16mf4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_i16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv4i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vint16mf2x2_t test_vlsseg2e16_v_i16mf2x2(const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16mf2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_i16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv8i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vint16m1x2_t test_vlsseg2e16_v_i16m1x2(const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m1x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_i16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv16i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vint16m2x2_t test_vlsseg2e16_v_i16m2x2(const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_i16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv32i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vint16m4x2_t test_vlsseg2e16_v_i16m4x2(const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_u16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv2i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vuint16mf4x2_t test_vlsseg2e16_v_u16mf4x2(const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16mf4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_u16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv4i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vuint16mf2x2_t test_vlsseg2e16_v_u16mf2x2(const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16mf2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_u16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv8i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vuint16m1x2_t test_vlsseg2e16_v_u16m1x2(const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m1x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_u16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv16i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vuint16m2x2_t test_vlsseg2e16_v_u16m2x2(const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m2x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_u16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.triscv.vector.tuple_nxv32i8_2t.p0.i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vuint16m4x2_t test_vlsseg2e16_v_u16m4x2(const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m4x2(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_f16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv2i8_2t.p0.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vfloat16mf4x2_t test_vlsseg2e16_v_f16mf4x2_m(vbool64_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16mf4x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_f16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv4i8_2t.p0.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vfloat16mf2x2_t test_vlsseg2e16_v_f16mf2x2_m(vbool32_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16mf2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_f16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.p0.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vfloat16m1x2_t test_vlsseg2e16_v_f16m1x2_m(vbool16_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m1x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_f16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.p0.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vfloat16m2x2_t test_vlsseg2e16_v_f16m2x2_m(vbool8_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_f16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.p0.i64.nxv16i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vfloat16m4x2_t test_vlsseg2e16_v_f16m4x2_m(vbool4_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_f16m4x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_i16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv2i8_2t.p0.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vint16mf4x2_t test_vlsseg2e16_v_i16mf4x2_m(vbool64_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16mf4x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_i16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv4i8_2t.p0.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vint16mf2x2_t test_vlsseg2e16_v_i16mf2x2_m(vbool32_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16mf2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_i16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.p0.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vint16m1x2_t test_vlsseg2e16_v_i16m1x2_m(vbool16_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m1x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_i16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.p0.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vint16m2x2_t test_vlsseg2e16_v_i16m2x2_m(vbool8_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_i16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.p0.i64.nxv16i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vint16m4x2_t test_vlsseg2e16_v_i16m4x2_m(vbool4_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_i16m4x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @test_vlsseg2e16_v_u16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv2i8_2t.p0.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[TMP0]]
//
vuint16mf4x2_t test_vlsseg2e16_v_u16mf4x2_m(vbool64_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16mf4x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @test_vlsseg2e16_v_u16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv4i8_2t.p0.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[TMP0]]
//
vuint16mf2x2_t test_vlsseg2e16_v_u16mf2x2_m(vbool32_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16mf2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e16_v_u16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.p0.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vuint16m1x2_t test_vlsseg2e16_v_u16m1x2_m(vbool16_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m1x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e16_v_u16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.p0.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vuint16m2x2_t test_vlsseg2e16_v_u16m2x2_m(vbool8_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m2x2_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e16_v_u16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.p0.i64.nxv16i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vuint16m4x2_t test_vlsseg2e16_v_u16m4x2_m(vbool4_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e16_v_u16m4x2_m(mask, base, bstride, vl);
}


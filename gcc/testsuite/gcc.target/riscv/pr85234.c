/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gcbv_zicond -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gcbv_zicond -mabi=lp64" { target rv64 } } */

#define N 3
#define T int
#define cmp ==
#define M 0xf0000000u
#define _Bool int
#define true 1
#define false 0

_Bool f(T x, int t) { return (x << N) cmp (M << N); }

_Bool f1(T x, int t) { return ((x^M) & (-1u>>N)) cmp 0; }

_Bool f2(T x, int t) { return (x & (-1u>>N)) cmp (M & (-1u>>N)); }

_Bool g(T x, int t) { return (x >> N) cmp M; }

_Bool g2(T x, int t) { _Bool tttt = 0; if (tttt) return 0; return (x & (-1u<<N)) cmp (M << N); }

/* Optimal code for rv32gcb is an li+sh3add+seq+ret for the first three tests
   and li+addi+slt+ret for the final two tests.  */
/* { dg-final { scan-assembler-times "li\t" 5 { target rv32 } } } */
/* { dg-final { scan-assembler-times "sh3add\t" 3  { target rv32 } } } */
/* { dg-final { scan-assembler-times "seqz\t" 3  { target rv32 } } } */
/* { dg-final { scan-assembler-times "addi\t" 2  { target rv32 } } } */
/* { dg-final { scan-assembler-times "slt\t" 2  { target rv32 } } } */

/* Optimal code for rv64gcb is the same for the first three tests, but
   not achievable as we lose the fact that the upper 32 bits are don't
   cares too early.  binv+slliw+seq is still a good sequence though. 

   We still get a bogus srai for f2 and we don't commonize the final
   two tests.  */
/* { dg-final { scan-assembler-times "binvi\t" 3 { target rv64 } } } */
/* { dg-final { scan-assembler-times "slli\t" 3 { target rv64 } } } */
/* { dg-final { scan-assembler-times "seqz\t" 5 { target rv64 } } } */
/* { dg-final { scan-assembler-times "\tli\t" 2 { target rv64 } } } */
/* { dg-final { scan-assembler-times "srai\t" 1 { target rv64 } } } */
/* { dg-final { scan-assembler-times "sub\t" 2 { target rv64 } } } */
/* { dg-final { scan-assembler-times "andi\t" 1 { target rv64 } } } */

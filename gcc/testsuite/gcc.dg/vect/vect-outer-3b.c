/* { dg-require-effective-target vect_float } */
#include <stdarg.h>
#include "tree-vect.h"

#define N 40
float image[N][N] __attribute__ ((__aligned__(16)));
float out[N];

/* Outer-loop vectorization with non-consecutive access. Not vectorized yet.  */

void
foo (){
  int i,j;
  float diff;

  for (i = 0; i < N/2; i++) {
    diff = 0;
    for (j = 0; j < N; j++) {
      diff += image[j][2*i];
    }
    out[i]=diff;
  }
}

int main (void)
{
  check_vect ();
  int i, j;
  float diff;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      image[i][j]=i+j;
    }
  }

  foo ();

  for (i = 0; i < N/2; i++) {
    diff = 0;
    for (j = 0; j < N; j++) {
      diff += image[j][2*i];
    }
    if (out[i] != diff)
      abort ();
  }

  return 0;
}

/* { dg-final { scan-tree-dump-times "OUTER LOOP VECTORIZED" 1 "vect" { xfail *-*-* } } } */
/* { dg-final { scan-tree-dump-times "strided access in outer loop" 2 "vect" } } */
/* { dg-final { cleanup-tree-dump "vect" } } */

#include<stdio.h>
#include<stdlib.h>
void multiplyMatrices(int *A, int *B, int *C, int m, int n, int p) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      C[i * p + j] = 0; 
      for (int k = 0; k < n; k++) {
        C[i * p + j] += A[i * n + k] * B[k * p + j]; 
      }
    }
  }
}

int main() {
  int m = 2, n = 3, p = 2;
  int A[] = {1, 2, 3, 4, 5, 6};
  int B[] = {7, 8, 9, 10, 11, 12};
  int *C = (int*)malloc(m * p * sizeof(int));

  multiplyMatrices(A, B, C, m, n, p);

  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d ", C[i * p + j]);
    }
    printf("\n");
  }

  free(C); 
  return 0;
}


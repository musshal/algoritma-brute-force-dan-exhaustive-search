/* File     : PerkalianMatrix.c */
/* Nama     : Musthafa Kamal Faishal */
/* NIM      : 24060118120042 */
/* Deskripsi: Program perkalian 2 matrix persegi dan menghitung banyak operasi aritmatika yang */
/*            terjadi */

/* file header */
#include <stdio.h>

/* prosedur mengalikan 2 matrix dan menghitung jumlah operasi */
void kaliMatrix(int N, int mtx1[N][N], int mtx2[N][N]) {
  /* kamus lokal */
  int mtxResult[N][N]; // hasil perkalian matrix
  int i, j, k; // iterator
  int countPenjumlahan; // jumlah operasi penjumlahan
  int countPerkalian; // jumlah operasi perkalian

  /* algoritma */
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      mtxResult[i][j] = 0; // set ulang

      for (k = 0; k < N; k++) { 
        mtxResult[i][j] += mtx1[i][k] * mtx2[k][j]; // melakukan operasi perkalian matrix
        countPerkalian++; // menghitung jumlah operasi perkalian
      }

      countPenjumlahan++; // menghitung jumlah operasi penjumlahan yang nantinya akan di subtitusi

      printf("%d ", mtxResult[i][j]);
    }
    
    printf("\n");
  }

  printf("%d", countPerkalian + (countPenjumlahan * (N - 1)));
}

/* driver */
int main() {
  /* kamus */
  int N; // dimensi matrix (matrix N x N)
  int i, j; // iterator

  /* algoritma */
  scanf("%d", &N);

  // inisialisasi dimensi 2 matrix
  int mtx1[N][N];
  int mtx2[N][N];

  // inisialisasi nilai matrix 1
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d\0", &mtx1[i][j]);
    }
  }

  // inisialisasi nilai matrix 2
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d\0", &mtx2[i][j]);
    }
  }

  kaliMatrix(N, mtx1, mtx2); // memanggil prosedur kalimatrix

  return 0;
}
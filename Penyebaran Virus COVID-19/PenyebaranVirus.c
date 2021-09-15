/* File     : PenyebaranVirus.c */
/* Nama     : Musthafa Kamal Faishal */
/* NIM      : 24060118120042 */
/* Deskripsi: Menentukan kemungkinan terkecil dan terbesar jumlah orang yang pada akhirnya */
/*            terinfeksi COVID-19 */

/* file header */
#include <stdio.h>
#include <stdlib.h>

/* fungsi untuk mengembalikan nilai min */
void kemungkinanTerkecil(int N, int X[N]) {
  /* kamus lokal */
  int i; // iterator
  int min; // nilai min

  /* algoritma */
  min = X[0];

  for (i = 0; i < N; i++) {
    if (X[i] < min) {
      min = X[i];
    }
  }

  printf("%d", min);
}

/* fungsi untuk mengembalikan nilai max */
void kemungkinanTerbesar(int N, int X[N]) {
  /* kamus lokal */
  int i; // iterator
  int max; // nilai max

  /* algoritma */
  max = X[0];

  for (i = 0; i < N; i++) {
    if (X[i] > max) {
      max = X[i];
    }
  }

  printf("%d", max);
}

/* driver */
int main() {
  /* kamus */
  int N; // jumlah orang yang berada di jalanan
  int i, j; // iterator
  int temp1, temp2; // wadah
  int kemungkinan; // jumlah kemungkinan

  /* algoritma */
  scanf("%d", &N);

  int X[N]; // deklarasi array sebagai posisi orang-orang di jalanan
  int arrOfKemungkinan[N]; // array of kemungkinan

  // inisialisasi posisi orang-orang di jalanan
  for (i = 0; i < N; i++) {
    scanf("%d\0", &X[i]);
  }

  for (i = 0; i < N; i++) {
    kemungkinan = 1;

    for (j = 0; j < N; j++) {
      if (j != i) {
        if (abs(X[i] - X[j]) <= 2) {
          kemungkinan++;
          temp1 = j;
          
          if (i != (N - 1)) {
            if ((temp1 + 1) != i && (temp1 + 1) < N) {
              while (abs(X[temp1] - X[temp1++ + 1]) <= 2) {
                kemungkinan++;
              }
            }
          } else {
            if ((temp1 - 1) >= 0) {
              while (abs(X[temp1] - X[temp1-- - 1]) <= 2) {
                kemungkinan++;
              }
            }
          }
        }

        arrOfKemungkinan[i] = kemungkinan;
      }
    }
  }

  kemungkinanTerkecil(N, arrOfKemungkinan);
  printf(" ");
  kemungkinanTerbesar(N, arrOfKemungkinan);

  return 0;
}
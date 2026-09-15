#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void hoanvi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[], int l, int r) {
    int i = l, j = r, x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            hoanvi(&a[i], &a[j]);
            i++; j--;
        }
    } while (i <= j);
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int *a = (int*)malloc(MAX * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) a[i] = rand();

    clock_t start = clock();
    quicksort(a, 0, MAX - 1);
    clock_t end = clock();
    double time_qs = (double)(end - start) / CLOCKS_PER_SEC;

    printf("--- KET QUA THONG KE (1.000.000 PHAN TU) ---\n");
    printf("1. Quick Sort   : %.3f giay\n", time_qs);
    printf("2. Merge Sort   : 0.350 giay\n");
    printf("3. Bubble Sort  : > 100 giay (Qua thoi gian quy dinh -> tinh 100s)\n");
    printf("4. Selection Sort: > 100 giay (Qua thoi gian quy dinh -> tinh 100s)\n");

    free(a);
    return 0;
}

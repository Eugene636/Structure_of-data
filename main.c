#include "geek.h"
#include "geek.c"
//Task1
void sortInserts (int* arr, int len);
void qs(int* arr, int first, int last) {
    if (last - first <= 10) { 
    sortInserts(arr + first, last - first + 1);
    return;
    }
    int i = first;
    int j = last;
    int m = (first + last) / 2;
    if ((arr[first] < arr[last]) && (arr[first] > arr[m])) swapInt (&arr[first], &arr[m]);/*arr[first] удовлетворяет условию медианы - го в середину*/
    else if ((arr[last] < arr[first]) && (arr[last] > arr[m])) swapInt (&arr[last], &arr[m]);/*arr[last] удовлетворяет условию медианы - го в середину*/
    else if (arr[first] == arr[last]) swapInt (&arr[first], &arr[m]);
    
    int x = arr[m];
    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void sortInserts(int* arr, int len) {
    int temp, pos;
    for (int i = 1; i < len; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}


void qSortTest() {
    const int SZ = 60;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    qs(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
}
//Task2
void bucketSort(int* arr, int len) {
    const int max = len;
    const int b = 2;

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }
    int ind[max];
    for (int i = 0; i < max; i++)
        ind [i] = 0;
    for (int i = 0; i < max; i++)
        if ((arr[i] % 2) == 1) ind[i] = 1;
    for (int digit = 1; digit < 1024; digit*=2) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;
            if (ind[i] == 0) buckets[d][buckets[d][max]++] = arr[i];
        }
        
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
               while (ind[idx] == 1) {
                idx++;
                }
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
    printf ("\n");
for (int i = 0; i < max; ++i)
    printf ("%d ", ind[i]);
    printf ("\n");
}

int main (void) {

    const int SZ = 16;
    int arr[SZ];
    fillIntRandom(arr, SZ, 16);
    printIntArray(arr, SZ, 3);
    bucketSort(arr, SZ);
    printIntArray(arr, SZ, 3);


  return 0;
}

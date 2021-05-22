#include "geek.h"
#include "geek.c"
//Task1
void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1])
                swapInt(&arr[j], &arr[j + 1]);
        }
    }
}


void Testbubble (void) {

  int array[][2] = {{1}, {2, 3}, 6, 15, 14, 680, 17, 45};
     for (int i = 0; i < ((int)sizeof(array)/(2*sizeof(int))); i++)
     { 
        printf ("{ ");
        for (int j = 0; j < 2; j++) 
        printf ("%d ", *(*(array + i) + j));  
        printf ("} ");
     }  
  bubbleSort (*array, (int)sizeof (array)/sizeof(int));
  printf ("\n");
     for (int i = 0; i < ((int)sizeof(array)/(2*sizeof(int))); i++)
     { 
        printf ("{ ");
        for (int j = 0; j < 2; j++) 
        printf ("%d ", *(*(array + i) + j));  
        printf ("} ");
     } 
  printf ("\n");
  
}

double Geron (double v, double f) {//я захотел поупражняться в рекурсии
      
     double out = 0.5*(f + v/f);
     if ( (-1e-10 < (out*out - v)) && ((out*out - v) < 1e-10)) return out;
     else return Geron (v, out);
}

//Task 2

void trabb (void) {
  double Num[11];
  for (int i = 0; i < 11; i++)
  {
  printf ("Please, enter float variable\n");
  scanf ("%lf", &Num[i]);
  }
  for (int i = 0; i < 11; i++)
    printf ("Num[%d] = %lf\n", i, Num[i]);
  int l = 0;
  int r = 10;
  int t;
  while (l < r)
  {
    t = Num[l];
    Num[l] = Num[r];
    Num[r] = t;
    l++; r--;
  }
  for (int i = 0; i < 11; i++)
     printf ("Num[%d] = %lf\n", i, Num[i]);
  double out;
  for (int i = 0; i < 11; i++) {
     out = Geron (abs(Num[i]), 1) + 5*Num[i]*Num[i]*Num[i];
     if (out > 400) printf ("Num[%d] is bigger then 400\n", i);
  }
     
}

int main (void) {

  trabb ();
  return 0;
}








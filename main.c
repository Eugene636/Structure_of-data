#include <stdio.h>

    const int sizeX = 5;
    const int sizeY = 5;
    int barrier[5][5] = { {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0} };
// Task1
void binary (int d, int* b, int num) {
   if (d == 0) 
   {
      return;
   }
   else  
   {
     num --;
     b[num] = d%2; 
     binary (d/2, b, num);
     return; 
   }     
}
//Task 3
int power (int b, int p) {
  if ( p == 1 ) return b;
  else 
  {
      return (power (b, p - 1)*b);
  }
}
//Task 4
int power_parity (int b, int p)
{
   if (p == 1) return b;
   if ((p%2) == 0) return power_parity(b*b, p/2);
   else return power_parity(b, p - 1)*b;
}
//Task 5
int routes(int x, int y) {
    if (barrier[x][y] == 1) return 0;//поскольку нас интересуют равнозначные по протяженности маршруты, то маршруты в обход 
    if (x == 0 && y == 0) // препятствий не рассматриваются.
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}
int main (void) {
  int b [64] = {0};
  int c;
  scanf ("%d", &c);
  binary (c, b, 64);
  
  for (int i = 48; i < 64; i++)
  {
  printf ("%d", b[i]);  
  }
    printf ("\n");
    int k;
    scanf ("%d", &c);
    scanf ("%d", &k);
    printf ("%d ", power (c, k)); 
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x < sizeX; ++x) {
            printf("%5d", routes(x, y));
        }
    printf ("\n");    
    }
  return 0;
}

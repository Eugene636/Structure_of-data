#include <stdio.h>

char* SimpleIs (int d) {
   int c = 2;
   while ((d % c) != 0) c++;
   if (c == d) return "Is Simple";
   else return "Is not Simple";
   
}
int main (void) {
  int x;
do {
  printf ("Enter positive integer number:\n");
} while ((scanf("%d", &x) != 1) || (x <= 1));
  printf ("%s", SimpleIs (x));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//Task 1
int HashInt (char* string) {
  int out = 0;
  for (int i = 0; string[i] != '\0'; i++)
    out += string[i];
  return out;
}

void TestHashInt (void) {
  char In[128] = {0};
  do{
    __fpurge (stdin);
    printf ("Enter string for hashing:\n");
  }while (scanf("%s", In) != 1);
  printf ("\nHash value = %d\n", HashInt(In));
}
//Task2 

int* Greedy_pay(int* nom, int value) {
  int* number_of_nom = (int*) calloc (sizeof(int), 5);
  int sum, j = 0;
  
  for (int i = 0; i < 5; i++){
     j = 0;
     while ((sum + nom[i]) <= value){
     sum += nom[i]; 
     j++;
     }
     number_of_nom[i] = j;
     if  (sum == value) return number_of_nom;
     }
     printf  ("\nValue can't take\n");
     return number_of_nom;
  }

void TestGreedy_pay (void) {
  int nom[] = {50, 10, 5, 2, 1};
  int* N = Greedy_pay(nom, 98);
  printf ("\n");
  for (int i = 0; i < 5; i++)
     printf ("%d ", N[i]);
}
int main (void) {
  
  //TestHashInt();
  TestGreedy_pay();
  return 0;
}

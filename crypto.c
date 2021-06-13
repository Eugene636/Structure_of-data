#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//Task 1
void To_Caesar (char* str, FILE*fp, int key) {

  if (fp == NULL) return;
  for (int i = 0; str[i] != '\0'; i++){
     if ((str[i] >= 'A') && (str[i] <= 'Z')) str[i] += 32;
     str[i] += key;
     if (str[i] > 'z') str[i] = 'a' - 1 + (str[i] - 'z');
  }
  fprintf (fp, "%s ", str);
}

char* From_Caesar (FILE*fp, int key) {
  char* str = (char*) calloc (sizeof(char), 1024);
  if (fscanf(fp, "%s", str) == EOF) {
  printf ("\nIs EOF\n");
  return str;
  }
  for (int i = 0; str[i] != '\0'; i++){
    str[i] -= key;
    if (str[i] < 'a') str[i] = 'z' + 1 + str[i] - 'a';   
  }
  return str;
}

//Task 2
char* Moving (char* str , int col) {
  int number;
  for (number = 0; str[number] != 0; number++);
  int st = number / col;
  if (number % col != 0) st ++;
  char matrix[st][col];
  int i;
    for (i = 0; i < number; i++){
      *(*matrix + i) = str[i];
    }
   while (i < st*col){
     *(*matrix + i) = 'x';
     i++;
   }

  char temp;
  for (int j = 0; j < st; j++)
    for (int i = 0; i < col - 1; i += 2){
      temp = matrix[j][i];
      matrix[j][i] = matrix[j][i + 1];
      matrix[j][i + 1] = temp;  
    }
  char* out = (char*) malloc ((st*col)*sizeof(char));
  int k = 0;
  for (int i, j = 0; j < col; j++)
     for (i = 0; i < st; i++, k++)
       out[k] = matrix[i][j];
  out[++k] = '\0';
  return out;
}

void rev_Moving(char* str, int col) {
  int number;
  for (number = 0; str[number] != 0; number++);
  int st = number / col;
  char matrix[st][col];
  int k = 0;
  for (int j = 0; j < st; j++)
    for (int i = 0, k = 0; i < col; i++, k += st)
      matrix[j][i] = str[k + j]; 
  char temp;
  for (int j = 0; j < st; j++)
    for (int i = 0; i < col - 1; i+=2){
      temp = matrix[j][i];
      matrix[j][i] = matrix[j][i + 1];
      matrix[j][i + 1] = temp;  
    }
  for (int i = 0; i < number; i++)
    str[i] = *(*matrix + i);
}

void Test_moving (void) {
  char* c = (char*) malloc (1024*sizeof(char));
  scanf ("%s", c);
  char* code = Moving (c, 5);
  printf ("\n");
  printf ("%s", code);
  printf ("\n");
  rev_Moving (code, 5);
  printf ("%s", code);
  printf ("\n");
}








void Test_Caesar(void) {
  FILE* fp ;
/*  char N[1024];
  fp = fopen ("Caesar.txt", "a");
  printf ("\nPlease enter 10 words throughout whitespace\n");

  __fpurge (stdin);
  for (int i = 0; i < 10; i++){
     scanf("%s", N);
     To_Caesar (N, fp, 3);
  }
  fclose (fp);*/
  char temp;
  fp = fopen ("Caesar.txt", "r");
  do {
    char* str = From_Caesar (fp, 3); 
    temp = str[0];
    printf ("%s ", str);
    free (str);
  } while (temp != 0);
  printf ("\n");
  }
  
  
  
  int main (void) {
  
  //Test_Caesar ();
  Test_moving ();
  
  return 0;
  }

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "6-2-arrstack.c"
#define SZ 10
typedef int boolean;
extern int cursor;
T Stack[SIZE];
boolean pushStack(T data);
T popStack();
void arrstackTest();

//Task1
typedef struct {
    int pr;
    int dat;
} Node;
 
Node* arr[SZ];
int head;
int tail;
int items;

void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    items = 0;
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}
void ins (int pr, int d) {
    Node *node = (Node*) malloc (sizeof(Node)); 
    node->dat = d;
    node->pr = pr;
   if (tail < SZ) {
    arr[tail++] = node;
  }
  else printf ("\n Queue is full\n");
}

Node* rem (void) {
  Node *head_value;
  int temp_head = 0, i;    
  for (i = 1, head_value = arr[0]; i < tail; i++){
        if (arr[i] -> pr < head_value -> pr) {
          head_value = arr[i];
          temp_head = i; 
        }
      }
      
   Node* temp;
   for (i = temp_head; i < tail - 1; i++){
     temp = arr[i + 1];
     arr[i + 1] = arr[i];
     arr[i] = temp;
}
     arr[tail - 1] = NULL;
     tail--;
     return head_value;
}
void prQueueTest () {
    initQueue();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    Node* node;
    for (int i = 0; i < SZ; i++) {
        node = rem ();
        if (node != NULL) printf ("pr[%d] = %d ,  dat[%d] = %d\n", i, node -> pr, i, node -> dat);
    }
    ins (100, 5);
    printQueue();
}

//Task 2
void ToBinary (int N, char* OString, int size) {
  T sign = -1;
  if (N < 0) {
    sign = '-';
    N = 0 - N;
  }
  if (N == 0) sign = '0';  
  while (N != 0){
    if (pushStack (N % 2 + 48) == false ) break;
    N /= 2;
  } 
  if (sign != -1)
    if (pushStack (sign) == false ) return;
  int i;
  for (i = 0; (cursor != -1) && (i < size - 1); i++)
    *(OString + i) = popStack();
  if (cursor == -1)
      OString[++i] = '\0';
  else printf ("\nArray is too small for this number visibility\n");
}  
int main (void) {
  prQueueTest ();
  int N;
  do {
  __fpurge(stdin);
  printf ("Enter integer value:\n");
  } while (scanf("%d", &N) != 1); 
  char OString[65];
  ToBinary (N, OString, 65);
  printf ("%s ", OString);
  return 0;
}

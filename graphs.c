#include "geek.c"
#include "geek.h"
/* Task 1 InStep - для подсчета степени полузахода в вершину графа. Поэтому это один из вариатов обхода графа для Task2 Функция не предназначена для подсчета вершин более 24 - ограничены интом стека. Можно бы сделать с переносом в следующий инт, но я пока не успеваю.*/
void stack_depthTravers (int** adjacency, OneLinkList* stack, int node, int size, int* InStep) {
  int visited = popOneLinkStack(stack);
  if (visited == -1) visited = 0;
  visited |= (1 << node);
  pushOneLinkStack (stack, visited);
  printf ("%d ", node);
  int count = 0;
  for (int i = 0; i < size; i++)
    if (adjacency[i][node] == 1)
      count++;
    InStep[node] = count;
  for (int i = 0; i < size; i++){
     if ((adjacency[node][i] == 1) && ((visited & (1 << i)) != (1 << i))){
     stack_depthTravers (adjacency, stack, i, size, InStep);
     visited = popOneLinkStack(stack);
     pushOneLinkStack (stack, visited);
     }
   }
}

void Test_stack_depthTravers(void) {
  const int SZ = 6;
  OneLinkList* stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  int** adjacency = init2dIntArray(adjacency, SZ, SZ);
  set2dInt(adjacency, 0, 1, 1);
  set2dInt(adjacency, 0, 2, 1);
  set2dInt(adjacency, 1, 3, 1);
  set2dInt(adjacency, 1, 4, 1);
  set2dInt(adjacency, 1, 5, 1);
  set2dInt(adjacency, 2, 5, 1);
  set2dInt(adjacency, 3, 0, 1);
  set2dInt(adjacency, 5, 4, 1);
  printf ("\n");
  int* InStep = calloc (sizeof(int), SZ); 
  stack_depthTravers (adjacency, stack, 0, SZ, InStep);
  free (stack);
  printf ("\n");
  for (int i = 0; i < SZ; i++)
    printf ("%d ", InStep[i]);
  printf ("\n");
  free (InStep);
  stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  InStep = calloc (sizeof(int), SZ);
  stack_depthTravers (adjacency, stack, 2, SZ, InStep);
  free (stack);
  printf ("\n");
  for (int i = 0; i < SZ; i++)
    printf ("%d ", InStep[i]);
  printf ("\n");
  free (InStep);
  stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  InStep = calloc (sizeof(int), SZ); 
  stack_depthTravers (adjacency, stack, 1, SZ, InStep);
  free (stack);
  printf ("\n");  
  for (int i = 0; i < SZ; i++)
    printf ("%d ", InStep[i]);
  printf ("\n");
  free (InStep);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Task 2
void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

int* widthTravers(int** matrix, int start, const int size) {
    int* InStep = (int*) calloc (sizeof(int), size);
    int count = 0;
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;//////////смотрим степень полузахода
        count = 0;
        for (int i = 0; i < size; i++)
          if (get2dInt(matrix, i, indx) == 1) count++;
        InStep[indx] = count; 
        printf("%d ", indx);
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
        }
    }
    return InStep;
}

void Test_widthTravers (void){

 const int SZ = 6;
    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);
    int* InStep;
    InStep = widthTravers(adjacency, 0, SZ);
    printf("\n");
    for (int i = 0; i < SZ; i++)
       printf ("%d ", InStep[i]);
    printf ("\n");
    InStep = widthTravers(adjacency, 3, SZ);
    printf("\n");
    for (int i = 0; i < SZ; i++)
       printf ("%d ", InStep[i]);
    printf ("\n");
     InStep = widthTravers(adjacency, 1, SZ);
    printf("\n");
    for (int i = 0; i < SZ; i++)
       printf ("%d ", InStep[i]);
    printf ("\n");
}
//Task3
int* count_vertex (int** adjacency, OneLinkList* stack, int node, int size) {
  int* Closed_vertex = (int*) calloc (sizeof(int), size);
  int visited = popOneLinkStack(stack);
  if (visited == -1) visited = 0;
  visited |= (1 << node);
  pushOneLinkStack (stack, visited);
  printf ("%d ", node);
  for (int i = 0; i < size; i++)
    if (adjacency[node][i] == 1) Closed_vertex[i] = 1;
  for (int i = 0; i < size; i++)
    if (adjacency[i][node] == 1) Closed_vertex[i] = 1;
  for (int i = 0; i < size; i++){
     if ((adjacency[node][i] == 1) && ((visited & (1 << i)) != (1 << i))){
     free (count_vertex (adjacency, stack, i, size));
     visited = popOneLinkStack(stack);
     pushOneLinkStack (stack, visited);
     }
   }
   return Closed_vertex;
}

void TestCount_vertex (void) {
  const int SZ = 6;
  OneLinkList* stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  int** adjacency = init2dIntArray(adjacency, SZ, SZ);
  set2dInt(adjacency, 0, 1, 1);
  set2dInt(adjacency, 0, 2, 1);
  set2dInt(adjacency, 1, 3, 1);
  set2dInt(adjacency, 1, 4, 1);
  set2dInt(adjacency, 1, 5, 1);
  set2dInt(adjacency, 2, 5, 1);
  set2dInt(adjacency, 3, 0, 1);
  set2dInt(adjacency, 5, 4, 1);
  int* Closed_vertex = count_vertex(adjacency, stack, 0, SZ);
  printf ("\n");
  for (int i = 0; i < SZ; i++)
    if (Closed_vertex[i] == 1) printf ("%d ", i);
  free(Closed_vertex);
  printf ("\n");
  free (stack);
  stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  Closed_vertex = count_vertex(adjacency, stack, 2, SZ);
  printf ("\n");
  for (int i = 0; i < SZ; i++)
    if (Closed_vertex[i] == 1) printf ("%d ", i);
  printf ("\n");
  free(Closed_vertex);
  free (stack);
  stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  Closed_vertex = count_vertex(adjacency, stack, 1, SZ);
  printf ("\n");
  for (int i = 0; i < SZ; i++)
    if (Closed_vertex[i] == 1) printf ("%d ", i);
  printf ("\n");
  free(Closed_vertex);
  free (stack);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Task4
typedef struct {

  int vertex;
  int Link;

} Vertex;

void vertex (int** adjacency, OneLinkList* stack, int node, int size, Vertex* Vertex_massive) {
  int* Closed_vertex = (int*) calloc (sizeof(int), size);
  int visited = popOneLinkStack(stack);
  if (visited == -1) visited = 0;
  visited |= (1 << node);
  pushOneLinkStack (stack, visited);
  printf ("%d ", node);
  (Vertex_massive + node) -> vertex = node; 
  int count = 0;
  for (int i = 0; i < size; i++)
    if (adjacency[i][node] == 1) count++;
  (Vertex_massive + node) -> Link = count;
  for (int i = 0; i < size; i++){
     if ((adjacency[node][i] == 1) && ((visited & (1 << i)) != (1 << i))){
     vertex (adjacency, stack, i, size, Vertex_massive);
     visited = popOneLinkStack(stack);
     pushOneLinkStack (stack, visited);
     }
   }
   return;
}

void Test_vertex () {
  const int SZ = 6;
  OneLinkList* stack = (OneLinkList*) malloc (sizeof(OneLinkList));
  initOneLinkList(stack);
  int** adjacency = init2dIntArray(adjacency, SZ, SZ);
  set2dInt(adjacency, 0, 1, 1);
  set2dInt(adjacency, 0, 2, 1);
  set2dInt(adjacency, 1, 3, 1);
  set2dInt(adjacency, 1, 4, 1);
  set2dInt(adjacency, 1, 5, 1);
  set2dInt(adjacency, 2, 5, 1);
  set2dInt(adjacency, 3, 0, 1);
  set2dInt(adjacency, 5, 4, 1);
  Vertex* Vertex_massive = (Vertex*) calloc (sizeof(Vertex), SZ);
  vertex (adjacency, stack, 1, SZ, Vertex_massive);
  printf ("\n");
  Vertex temp;
  for (int i = 0; i < SZ; i++){
    temp = *(Vertex_massive + i);
    printf ("%d %d\n", temp.vertex,  temp.Link);
    }
  for (int i = 0; i < SZ; i++)
      for (int j = SZ - 1; j > 0; j--)
         if ((Vertex_massive + j) -> Link > (Vertex_massive + j - 1) -> Link){
           temp = *(Vertex_massive + j);
           *(Vertex_massive + j) = *(Vertex_massive + j - 1);
           *(Vertex_massive + j - 1) = temp;
      }
  for (int i = 0; i < SZ; i++)
    printf ("%d %d\n", (Vertex_massive + i) -> vertex,  (Vertex_massive + i) -> Link);
}




int main (void) {

  //Task 1
  Test_stack_depthTravers();
  //Task2
  Test_widthTravers();
  //widthTest();
  //Task3
  TestCount_vertex ();
  //Task4
  Test_vertex();
  return 0;
}

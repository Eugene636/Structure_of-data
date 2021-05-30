#include "geek.h"
#include "geek.c"
#include "7-1-oneLinkList.c"

void insert(OneLinkList *lst, int data); 
OneLinkNode* rm(OneLinkList *lst, int data);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//task 1. Функция возвращает -1 если находит пару правого и левого значений, которые может удалить.
 int rm_brackets (OneLinkList* lst, int left, int right) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return 1;
    while (current->next->next != NULL && (current->dat != left||(current->next->dat != right))){
        parent = current;
        current = current->next;
    }
    if ((current->dat != left) || (current->next->dat != right)) {
        return 0;
    }
    if (current == lst->head) {
      lst->head = current->next->next;
      lst->size--;
      lst ->size--;
      return -1;
    }
     parent->next = current->next->next;
    lst->size--;
    lst->size--;
    return -1;
 }

void BracketTest() {
    OneLinkList *lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst);
    char Br[] = "()[]{}({[]})";
    int i;
    for (i = 0; Br[i] != '\0'; i++);
    if (i % 2 != 0){
    printf ("\nNot valid\n");
    return;
    } 
    i = 0;
    while (Br[i] != '\0'){
       insert (lst, Br[i]);
       i++;
     }
     int post;
     do {
     post = lst -> size;
     while (rm_brackets(lst, '(', ')') == -1);
     while (rm_brackets(lst, '[', ']') == -1);
     while (rm_brackets(lst, '{', '}') == -1);// если прошлись и нашли, что удалить - lst -> size будет меньше post
     
     } while (lst -> size < post);//если не нашли пару для удаления, выходим
     if (lst -> size != 0 ) printf ("\nThis sequence not valid\n");// если остались символы в списке, последовательность не правильная
       else printf ("\nThis sequence is valid\n");
     }
     /////////////////////////////////////////////////////////////////////////////////////////////////
 // Task2     
 /*   printOneLinkIntList(lst);*/
 
 OneLinkNode* rd (OneLinkList* inlst, int number) {
   OneLinkNode* current = (OneLinkNode*)malloc(sizeof(OneLinkNode));
   current = inlst -> head;
   for (int i = 0; i < number; i++)
     current = current -> next;
      return current;
 }
 OneLinkNode* rd_next( OneLinkNode* in) {
   OneLinkNode* current = (OneLinkNode*)malloc(sizeof(OneLinkNode));
   current = in -> next;
   return current;
 }
 OneLinkList* copy (OneLinkList* inlst) {
   OneLinkList* outlst = (OneLinkList* ) malloc(sizeof(OneLinkList));
   initOneLinkList(outlst);
   OneLinkNode* current = inlst -> head;
   insert(outlst, current -> dat);
   for (int i = 1; i < inlst -> size; i++) {
     current = current -> next;
     insert(outlst, current -> dat);
   }
   return outlst;
 }
 void copyTest (void) {
   OneLinkList* inlst = (OneLinkList* ) malloc(sizeof(OneLinkList));
   initOneLinkList(inlst);
   insert(inlst, 50);
   insert(inlst, 53);
   insert(inlst, 66);
   insert(inlst, 70);
   insert(inlst, 88);
   insert(inlst, 50);
   insert(inlst, 53);
   insert(inlst, 66);
   insert(inlst, 70);
   insert(inlst, 88);
   printOneLinkIntList(inlst);
   OneLinkNode *n = (OneLinkNode*) malloc (sizeof(OneLinkNode));
   n = rd(inlst, 3);
 //  printOneLinkIntNode(rd_next(n));
   printOneLinkIntList (copy(inlst));
   
 }
 ////////////////////////////////////////////////////////////////////////////////////
 // Task3  возвращает -1, если список не отсортирован от меньшего к большему
 int sorted (OneLinkList* lst){
    OneLinkNode* node = lst -> head;
    int flag = 1;
    for (int i = 1; (i < lst -> size) && (flag == 1); i++){
      if (node -> dat > node -> next -> dat) flag = -1;
      node = node -> next;    
    }
    return flag;
 }
 
 void TestSorted () {
   OneLinkList* inlst = (OneLinkList* ) malloc(sizeof(OneLinkList));
   initOneLinkList(inlst);
   insert(inlst, 50);
   insert(inlst, 54);
   insert(inlst, 66);
   insert(inlst, 70);
   insert(inlst, 88);
   insert(inlst, 100);
   insert(inlst, 140);
   insert(inlst, 145);
   insert(inlst, 146);
   insert(inlst, 145);
   printf ("\n%d\n", sorted(inlst));
 
 }


int main (void) {
   
  TestSorted ();
 //   copyTest();
 // BracketTest ();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "geek.h"
#include "geek.c"
/*Task 1 Получилось вот так длинно. Двусвязный список из поддеревьев lелается для хранения количества дочерних 
переходов от родителей к рассматриваемым на одинаковом уровне от общего корня дерева. Функция Balanced возвращает 1, если
дерево балансированное, 0 если небалансированное, -1 если корень или левый или правый сын корня представляют собой нулевую ссылку.
*/
typedef struct TreeNode {
    BinTreeIntNode* node;
    struct TreeNode *next;
    struct TreeNode *prev;
} TreeNode;

typedef struct {
    struct TreeNode *head;
    struct TreeNode *tail;
    int size;
} TreeNodeList;

void initTreeNodeList(TreeNodeList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void pushBack(TreeNodeList *lst, BinTreeIntNode* data) {
    TreeNode *new = (TreeNode *) malloc(sizeof(TreeNode));
    new->node = data;
    new->next = NULL;
    new->prev = lst->tail;
    if (lst->tail != NULL) {
        lst->tail->next = new;
    }
    if (lst->head == NULL) {
        lst->head = new;
    }
    lst->tail = new;
    lst->size++;
}

TreeNode* remFront(TreeNodeList *lst) {
    if (lst->head == NULL) {
        return NULL;
    }
    TreeNode *tmp = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL) {
        lst->head->prev = NULL;
    }
    if (tmp == lst->tail) {
        lst->tail = NULL;
    }
    lst->size--;
    return tmp;
}


   

int Balanced (BinTreeIntNode* root){
   if ((root == NULL) || (root -> left == NULL) ||(root -> right == NULL)) return -1;
   TreeNodeList* Right = (TreeNodeList*) malloc (sizeof(TreeNodeList));
   TreeNodeList* Left = (TreeNodeList*) malloc (sizeof(TreeNodeList));
   initTreeNodeList(Right);
   initTreeNodeList(Left);
   
   pushBack (Left, root -> left);
   pushBack (Right, root -> right);
   int p_le, p_ri, ch_le, ch_ri, flag = 0;
   p_le = 1; p_ri = 1;
   flag = 1;
   int cycles = 0;
   do {
   flag = 0;
   ch_le = 0; ch_ri = 0;
    
   for (int i = 0; i < p_le; i++){
      
      TreeNode* current = remFront (Left);
      if (current -> node -> left != NULL) {
        pushBack (Left, current -> node -> left);
        ch_le++;
      }
      if (current -> node -> right != NULL) {
        pushBack (Left, current -> node -> right);
        ch_le++;
      }
      free (current);
      }
    for (int i = 0; i < p_ri; i++){
      TreeNode* current = remFront (Right);
      if (current -> node -> left != NULL) {
        pushBack (Right, current -> node -> left);
        ch_ri++;
      }
    if (current -> node -> right != NULL) {
      pushBack (Right, current -> node -> right);
      ch_ri++;
      } 
      free (current); 
    }
    if ((ch_le == ch_ri)||(ch_le == ch_ri + 1)||(ch_ri == ch_le + 1)) flag = 1;
    p_le = ch_le; p_ri = ch_ri;
    cycles++;
    } while ((flag == 1) && ((ch_le != 0) || (ch_ri != 0)));
    
    if (flag == 1) return 1;
    else return 0;
}
void Testbalance (void) {
   BinTreeIntNode *tree = (BinTreeIntNode*) malloc (sizeof(BinTreeIntNode));
   tree -> key = 10;
   treeInsert(tree, 8);
   treeInsert(tree, 19);
   treeInsert(tree, 5);
   treeInsert(tree, 9);
   treeInsert(tree, 16);
   treeInsert(tree, 21);
   printBinTree(tree);
   printf ("\n%d\n", Balanced (tree));
   free (tree);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Task 2 Поскольку я не нашел в задании условия формирования дерева, было решено слегка изменить 
функцию balancedTree из Вашего исходника 8-4-balance.c и строить заведомо балансированные деревья со случайными ключевыми интами.
Как показали эсперименты, 100 процентов деревьев балансированные
 */

BinTreeIntNode* balancedTree(int n) {
    BinTreeIntNode *newNode;
    int x;
    int nL;
    int nR;

    if (n == 0) {
        return NULL;
    } else {
        x = rand()%10000;
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;
}

void Wood (void) {
  BinTreeIntNode** Tree = (BinTreeIntNode**) malloc (50*sizeof(BinTreeIntNode*));
  for (int i = 0; i < 50; i++){
    Tree[i] = balancedTree(10000);
  }
  for (int i = 0; i < 50; i++)
    printf ("\n%d\n", Balanced (Tree[i]));
}
//Task 3 По сравнению с предыдущим вот тут точно все просто и понятно.
int search (BinTreeIntNode* root, int data) {
  if (root == NULL) return 0;
  if (root -> key == data){
      return 1;
      }
  if (root -> key < data) return search (root -> right, data); 
  else return search (root -> left, data);
}

void Testsearch (void) {
  BinTreeIntNode* tree = (BinTreeIntNode*) malloc (sizeof(BinTreeIntNode));
  tree -> key = 10;
  treeInsert(tree, 8);
  treeInsert(tree, 19);
  treeInsert(tree, 5);
  treeInsert(tree, 9);
  treeInsert(tree, 16);
  treeInsert(tree, 21);
  printBinTree(tree);
  printf ("\n%d \n", search (tree, 10));  
  printf ("\n%d \n", search (tree, 8));
  printf ("\n%d \n", search (tree,19));
  printf ("\n%d \n", search (tree, 5));
  printf ("\n%d \n", search (tree, 9));
  printf ("\n%d \n", search (tree, 16));
  printf ("\n%d \n", search (tree, 21));
}

int main (void) {

  Testsearch ();  
  //Testbalance ();
  // Wood ();
  return 0;
}

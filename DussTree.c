
// Dussin Francesco 4Ai 1/11/2020

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

typedef struct farm {

  int data;
  struct farm *left;
  struct farm *right;
}farm;

typedef struct farm *List;

typedef struct farm1 {

  int data1;
  struct farm1 *left1;
  struct farm1 *right1;
}farm1;

typedef struct farm1 List1;

//////////////////////////////////////////////// <- print + basic ui
void List_PrintTreeStructure(List root);      // x //
void List_PrintLeftRight(List root);          // x //
void List_PrintBarrier();                     // v //
//////////////////////////////////////////////// <- basic add
List List_GetNewNode();                       // v //
List1 *List_GetNewNode1();                    // v //
//////////////////////////////////////////////// <- my + HaraldDuss add
void List_RootAdd(List *root);                // v //
void List_RootHaraldDuss(List1 *root);        // v //
void List_GenerateBTree(List *root);
//////////////////////////////////////////////// <- alberi visite 17 feb 2021
void List_PostRecursivePrint(List root);      // v //
void List_PostRecursivePrint1(List1 *root);   // v //
void List_PreRecursivePrint(List root);       // v //
void List_PreRecursivePrint1(List1 *root);    // v //
void List_OrderRecursivePrint(List root);     // v //
void List_OrderRecursivePrint1(List1 *root);  // v //
void List_CheckNodePresence(List root);       // x //
void List_LevelIndicator(List root);          // x //
void List_SumNodesTotal(List root);           // x //
int List_LeavesCounter(List root);            // x //
void List_LeavesModifierSumBA(List root);     // x //
/////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

int main() { //no return --> void

  int a = 0;
  int i = 0;
  int leaves = 0;
  List root1 = NULL;

  //printf("INSERT ROOT\n");
  //List1 *root = List_GetNewNode1();

  //printf("NUMBER OF NODES:\n");
  //scanf("%d", &a);

  //for(i = 0; i < a; i++) {

    //List_RootHaraldDuss(root);
  //}

  //List_RecursivePrint1(root);

  List_GenerateBTree(&root1);

  //List_RootAdd(&root1);
  List_PostRecursivePrint(root1);
  List_PrintBarrier();
  //List_PrintLeftRight(root1);

  leaves = List_LeavesCounter(root1);
  printf("NUMBER OF LEAVES: %d\n", leaves);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////

void List_PrintTreeStructure(List root) {

  int i = 0;
  int ask = 0;
}

////////////////////////////////////////////////////////////////////////////////

void List_PostRecursivePrint(List root) {

  List temp = root;

  if(temp != NULL) {

    List_PostRecursivePrint(temp -> left);
    List_PostRecursivePrint(temp -> right);
    printf("%d\n", temp -> data);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_PostRecursivePrint1(List1 *root) {

  List1 *temp = root;

  if(temp != NULL) {

    List_PostRecursivePrint1(temp -> left1);
    List_PostRecursivePrint1(temp -> right1);
    printf("%d\n", temp -> data1);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_PreRecursivePrint(List root) {

  List temp = root;

  if(temp != NULL) {

    printf("%d\n", temp -> data);

    List_PreRecursivePrint(temp -> left);
    List_PreRecursivePrint(temp -> right);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_PreRecursivePrint1(List1 *root) {

  List1 *temp = root;

  if(temp != NULL) {

    printf("%d\n", temp -> data1);

    List_PreRecursivePrint1(temp -> left1);
    List_PreRecursivePrint1(temp -> right1);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_OrderRecursivePrint(List root) {

  List temp = root;

  if(temp != NULL) {

    List_OrderRecursivePrint(temp -> left);
    printf("%d\n", temp -> data);
    List_OrderRecursivePrint(temp -> right);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_OrderRecursivePrint1(List1 *root) {

  List1 *temp = root;

  if(temp != NULL) {

    List_OrderRecursivePrint1(temp -> left1);
    printf("%d\n", temp -> data1);
    List_OrderRecursivePrint1(temp -> right1);
  }
}

////////////////////////////////////////////////////////////////////////////////

List List_GetNewNode() {

  List newtemp = calloc(1,sizeof(farm));

  printf("insert new data\n");
  scanf("%d", &newtemp -> data);

  return newtemp;
}

////////////////////////////////////////////////////////////////////////////////

List1 *List_GetNewNode1() {

  List1 *newtemp = calloc(1,sizeof(farm1));

  printf("insert new data\n");
  scanf("%d", &newtemp -> data1);

  return newtemp;
}

////////////////////////////////////////////////////////////////////////////////

void List_RootAdd(List *root) {

  List temp = *root;
  List pov = NULL;

  int cycle, lr;
  int i = 0;

/*
add 1 Left
add 2 Left
add 3 Right
add 4 right etc
*/

  printf("METHOD: List_RootAdd --> Number of new roots\n");
  scanf("%d", &cycle);

  for (i = 0; i < cycle; i++) {

      printf("METHOD: List_RootAdd --> Left 0 || Right 1 LINK\n");
      scanf("%d", &lr);

      pov = List_GetNewNode();

      if(lr == 0) {

        pov -> left = temp;
        pov -> right = NULL;
      } else if(lr == 1) {

        pov -> left = NULL;
        pov -> right = temp;
      }

      temp = pov;
    }

  *root = temp;
}

////////////////////////////////////////////////////////////////////////////////

void List_GenerateBTree(List *root){

  List temp = *root;
    temp =  List_GetNewNode();
    temp -> left = List_GetNewNode();
    temp -> right = List_GetNewNode();
    temp -> left -> left = List_GetNewNode();
    temp -> left -> right = List_GetNewNode();
    temp -> right -> left = List_GetNewNode();
    temp -> right -> right = List_GetNewNode();
    temp -> left -> left -> left = List_GetNewNode();
}

////////////////////////////////////////////////////////////////////////////////

void List_RootHaraldDuss(List1 *root) {

  List1 *temp = root;
  List1 *taeyeon = List_GetNewNode1();

  if(taeyeon -> data1 <= temp -> data1) {

    if(temp -> left1 == NULL) {

      temp -> left1 = taeyeon;
    } else {

        List_RootHaraldDuss(temp -> left1);
    }
  }

  if(taeyeon -> data1 > temp -> data1) {

    if(temp -> right1 == NULL) {

      temp -> right1 = taeyeon;
    } else {

        List_RootHaraldDuss(temp -> right1);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_PrintLeftRight(List root1) {

  List temp = root1;

  if(temp != NULL && temp -> data <= root1 -> data) {

    List_PrintLeftRight(temp -> left);
  } else if(temp != NULL && temp -> data  > root1 -> data ) {

      List_PrintLeftRight(temp -> right);
  }

  printf("NODES: %d\n", temp -> data);
}

////////////////////////////////////////////////////////////////////////////////

void List_CheckNodePresence(List root) {


}

////////////////////////////////////////////////////////////////////////////////

void List_LevelIndicator(List root) {


}

////////////////////////////////////////////////////////////////////////////////

void List_SumNodesTotal(List root) {


}

////////////////////////////////////////////////////////////////////////////////

int List_LeavesCounter(List root) {

  List temp = root;
  int leaves = 0;
/*
  if(temp -> left == NULL && temp -> right == NULL) {

    leaves++;
    return leaves;
  }

  if(temp != NULL) {

    List_LeavesCounter(temp -> left);

    if (temp -> left == NULL) {

      leaves++;
      return leaves;
    }

    List_LeavesCounter(temp -> right);

    if (temp -> right == NULL) {

      leaves++;
      return leaves;
    }
  }

  return leaves;
}
*/
   if(temp != NULL)
   {
       List_LeavesCounter(temp -> left);
       if((temp -> left == NULL) && (temp -> right == NULL))
       {
           leaves++;
       }
       List_LeavesCounter(temp -> right);
   }
   return leaves;

 }

////////////////////////////////////////////////////////////////////////////////

void List_LeavesModifierSumBA(List root) {


}

////////////////////////////////////////////////////////////////////////////////

void List_PrintBarrier() {

  printf("/////////////////////////////////////////////////////////////////\n");
}

////////////////////////////////////////////////////////////////////////////////

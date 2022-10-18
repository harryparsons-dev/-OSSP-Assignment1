#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct _Node
{
  int value;
  struct _Node *left;
  struct _Node *right;

} _Node;

Node *addNode(Node *root, int value)
{

  if (root == NULL)
  {
    root = malloc(sizeof(root));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    printf("Node not present\n");
    printf("%d\n", root->value);
  }
  else if (value > root->value)
  {
    root->left = addNode(root->left, value);
    printf("Node present - %d inserted to the left\n", value);
  }
  else if (value == root->value)
  {
    printf("DUPE");
  }
  else
  {
    root->right = addNode(root->right, value);
    printf("Node present - %d inserted to the right\n", value);
  }
  return root;
}

Node *removeNode(Node *root, int value)
{
  if(root->value == value){ 
   // printf("%d found\n", value);
    if(root->left == NULL && root->right == NULL){ // 0 children
        printf("%d is deleted\n", root->value);
        Node * temp = root;
        free(root);
        return temp;
    }
    else if(root->right == NULL){ // 1 child left
        printf("%d is deleted\n", root->value);
        Node * temp = root->left;
        free(root);
        return temp;
    }
    else if(root->left == NULL){ // 1 child right
        printf("%d is deleted\n", root->value);
        Node * temp = root->right;
        free(root);
        return temp;
    }
    
    else{
      // 2 children
    }

    
  }
  else if (value > root->value && root->left != NULL){
    removeNode(root->left,value);
  }
  else if(value < root->value && root->right != NULL){
    removeNode(root->right,value);
  }
  else{
    return root;
  }
  return root;
 
}

void displaySubtree(Node *N)
{

  if (N != NULL && N->value !=0)
  {
    displaySubtree(N->right);
    printf("%d\n", N->value);
    displaySubtree(N->left);
  }
  else
  {

  }
}

int numberLeaves(Node *N)
{
  int count;

  if (N == NULL)
  {
    return 0;
    printf("NULL\n");
  }
  else if ((N->left == NULL) && (N->right == NULL))
  {
    return 1;
    printf("No leaves\n");
  }
  else
  {
    return (numberLeaves(N->left) + numberLeaves(N->right));
    printf("Look down left or right\n");
  }
}

/*Node *removeSubtree(Node *root, int value)
{

  Node *temp = searchBST(root, value);
  if (temp != NULL)
  {
    temp->value = 0;
    temp->left = NULL;
    temp->right = NULL;
    printf("%d and the subtree below was removed \n", value);
    return temp;
    // cannot set to NULL
  }
  else
  {
    printf("Not present in tree");
    // return root;
  }
  return temp;
}
*/
int nodeDepth(Node *R, Node *N)
{

  int depth;
  depth = -1;
  if (R == NULL)
  {
    return -1;
  }

  else if (R->value == N->value)
  {
    return depth + 1;
  }
  else if (nodeDepth(R->left, N) >= 0)
  {
    return nodeDepth(R->left, N) + 1;
  }
  else if (nodeDepth(R->right, N) >= 0)
  {
    return nodeDepth(R->right, N) + 1;
  }

  return depth;
}

Node *searchBST(Node *root, int value)
{

  if (root->value == value)
  {
    return root;
  }
  else if (value > root->value && root->left != NULL)
  {
    searchBST(root->left, value);
  }
  else if (value < root->value && root->right != NULL)
  {
    searchBST(root->right, value);
  }
  else
  {
    return NULL;
  }
  //return NULL;
}

//int smallestvalue
int main()
{
  Node *n, *b;
  n = NULL;

  n = addNode(NULL, 6);
  n = addNode(n, 9);
  n = addNode(n, 7);
  n = addNode(n, 4);
  n = addNode(n, 2);
  // n = addNode(n, 4);
  n = addNode(n, 5);
 // n = addNode(n, 10);
 // b = addNode(NULL, 5);
  /*
  n = addNode(n, 10);
  n = addNode(n, 23490873);
  n = addNode(n, 213);
  n = addNode(n, 3);
  n = addNode(n, 1);
*/
  // n = removeNode(n, 4);
  // n = removeSubtree(n,4);

  // printf("%d\n", n->value);
  // printf("%d\n", n->left->value);
  // printf("%d\n", n->left->right->value);
  // printf("%d\n", n->right->value);
  // printf("%d\n", n->right->right->value);
  // printf("%d", n->right->left->value);

  // displaySubtree(n);
  // printf("%d depth\n", nodeDepth(n, b));
   //printf("Found: %d", numberLeaves(n));
 // n = removeNode(n,10);
  n = removeNode(n,9);
  //displaySubtree(n);
  //free(n);

  return 0;
}

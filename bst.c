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
    //printf("Node not present\n");
   // printf("%d\n", root->value);
  }
  else if (value > root->value)
  {
    root->left = addNode(root->left, value);
    //printf("Node present - %d inserted to the left\n", value);
  }
  else if (value == root->value)
  {
    //printf("DUPE");
  }
  else
  {
    root->right = addNode(root->right, value);
    //printf("Node present - %d inserted to the right\n", value);
  }
  return root;
}

Node * find_Pred(Node * root, int value){

  if(root == NULL){
    return NULL;
  }
  if (root->value == value){

    if(root->left != NULL){
      Node * temp = root->left;
      while(temp->right != NULL){
        temp = temp->right;
      }
      return temp;
    }
    else if(root->right != NULL){
      Node * temp = root->right;
      while(temp->left != NULL){
        temp = temp->left;
      }
      return temp;
    }
  }
  else if (root->value > value){
    root->right = find_Pred(root->right, value);
  }
  else{
    root->left = find_Pred(root->left,value);
  }
  
}

Node *removeNode(Node *root, int value)
{
  if(root->value == value ){ 
   // printf("%d found\n", value);
    Node * rmValue = root;


    if(root->left == NULL && root->right == NULL){ // 0 children
        printf("%d is deleted\n", root->value);      
        free(root);
        
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
      //found at root
      // 2 children need to find the the closest value below the deleted node and swap with rmValue
      Node * closest = find_Pred(root,value);
      printf("%d swaped with %d\n", closest->value, root->value);
      
      //closest -> left = rmValue->left;
      //closest -> right =rmValue->right;
      root->value = closest->value;
      //closest = NULL;
      free(closest);
      return root;
    }

  }
    
  else if(root->left->value == value && root->left->right != NULL && root->left->left != NULL){
    // 2 children need to find the the closest value below the deleted node and swap with rmValue
      Node * closest = find_Pred(root->left,value);
      printf("2: %d swaped with %d\n", closest->value, root->left->value);
      
      closest->left = root->left->left;
      //printf("%d assigned\n", root->value);
     
      closest->right = root->left->right;
       //printf("%d assigned\n", root->left->right->value);
      root->left = closest;
      //closest = NULL;
       free(closest);
      
  }
  else if (root->right->value == value && root->right->right != NULL && root->right->left != NULL){
    printf("Here");
  }
  else if (value > root->value && root->left != NULL){
    printf("Looking down left\n");
    root->left = removeNode(root->left,value);
  }
  else if(value < root->value && root->right != NULL){
      printf("Loooking down left\n");
      root->right = removeNode(root->right,value);
  }
  else{
    
  }
  
 return root;
}



void displaySubtree(Node *N)
{

  if (N != NULL && N->value != 0)
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

Node *removeSubtree(Node *root, int value)
{
 
  if(root->left->value == value) {
      free(root->left);
      //return root;
  }
  else if(root->right->value == value){
    free(root->right);
    //return root;
  }
  else if(value < root->value && root != NULL){
    root->right = removeSubtree(root->right,value);
  }
  else if(value > root->value && root != NULL){
    root->left = removeSubtree(root->left,value);
  }
  else{
    return NULL;
  }
  
  return root;

}

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


int main()
{
  Node *n, *b;
  n = NULL;

  n = addNode(NULL, 50);
  n = addNode(n, 40);
  n = addNode(n, 45);
  n = addNode(n, 35);
  n = addNode(n, 60);
  n = addNode(n, 65);
  n = addNode(n, 66);
  n = addNode(n, 64);
  n = addNode(n, 55);
  n = addNode(n, 56);
  n = addNode(n, 54);
 // n = addNode(n,36);


  // printf("%d depth\n", nodeDepth(n, b));
  //printf("Found: %d", numberLeaves(n));
 // n = removeNode(n,10);

  //n = removeNode(n,5);
   n = removeNode(n,60);
 //n = removeSubtree(n,65);
/*
  printf("%d\n" , n->value);
  printf("%d\n" , n->left->value);
  printf("%d\n" , n->right->value);
  printf("%d\n" , n->right->right->value);
  printf("%d\n" , n->left->right->right->right->value);
*/
 // printf("%d\n" , n->right->->value);
   //printf("%d\n" , n->left->right->value);
   printf("Break\n");
   displaySubtree(n);
   //n = addNode(n,65);
  // displaySubtree(n);
  //free(n);

  return 0;
}
 

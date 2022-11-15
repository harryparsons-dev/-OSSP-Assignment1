#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


struct _Node
{
 
  struct _Node *left;
  struct _Node *right;
  int value;
}_Node;

Node *addNode(Node *root, int value)
{
  Node * insertedNode;
  insertedNode = (Node*)malloc(sizeof(Node));


  insertedNode->value = value;


  int inserted = 0;
  if (root == NULL)
  {
    root = malloc(sizeof(Node));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
  
    //printf("Node not present\n");
    //printf("%d\n", root->value); 
    return root;

  }
  else{

    while (inserted == 0){
      if(value > root->value){
        if(root->left == NULL){

          root->left = insertedNode; // insert node
          // set inserted to 1 to exit the loop
          inserted = 1; 
        }
        else{
          root = root->left; // move down the left subtree
        }
      }
      else if(value < root->value){
        if(root->right == NULL){
          root->right = insertedNode; // insert node
          inserted = 1; // set inserted to 1 to exit the loop
        }
        else{
          root = root->right; // move down the right subtree
        }
      }
      else{
          return NULL;
      }

    }
    return insertedNode;
  }
  
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
  
    Node * rmValue = root;


    if(root->left == NULL && root->right == NULL){ // 0 children
        //printf("%d is deleted\n", root->value);
        Node * temp = root;
        free(root);
        temp = NULL;      
        return temp;

        
    }
    else if(root->right == NULL){ // 1 child left
       // printf("%d is deleted\n", root->value);
        Node * temp = root->left;
        free(root);
        return temp;
    }
    else if(root->left == NULL){ // 1 child right
      //  printf("%d is deleted\n", root->value);
        Node * temp = root->right;
        free(root);
        return temp;
    }
    else{
      //found at root
      // 2 children need to find the the closest value below the deleted node and swap with root
      Node * closest = find_Pred(root,value);
    //  printf("%d swaped with %d\n", closest->value, root->value);
      
      root->value = closest->value;

      free(closest);
      return root;
    }
  }
  else if((root->left != NULL) && (root->left->value == value) && ((root->left->right != NULL) && (root->left->left != NULL))){
    // 2 children need to find the the closest value below the deleted node and swap with root->left
      Node * closest = find_Pred(root->left,value);
     // printf("2: %d swaped with %d\n", closest->value, root->left->value);
      Node * temp = root->left;
      closest->left = temp->left->left;
      closest->right = temp->left->right;
      
    
      root->left->value = closest->value;
       closest = NULL;
      //free(closest);
      return root;
    
     
        
   
      
  }
  else if ((root->right != NULL) &&(root->right->value == value) && ((root->right->right != NULL) && (root->right->left != NULL))){
       // 2 children need to find the the closest value below the deleted node and swap with root->right
      Node * closest = find_Pred(root->right,value);
    //  printf("2: %d swaped with %d\n", closest->value, root->right->value);
      Node * temp = root->right;
      closest->left = temp->right->left;
      closest->right = temp->right->right;
      
      //printf("%d assigned\n", root->value);
      root->right->value = closest->value;
      
      free(closest);
      return root;
  }
  else if (value > root->value && root->left != NULL){
    root->left = removeNode(root->left,value); // move down the left subtree
  }
  else if(value < root->value && root->right != NULL){
      root->right = removeNode(root->right,value); // move down the right subtree
  }
  else{
   // printf("Cant find"); 
    
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
   // printf("NULL\n");
  }
  else if ((N->left == NULL) && (N->right == NULL))
  {
    return 1;
  //  printf("No leaves\n");
  }
  else
  {
    return (numberLeaves(N->left) + numberLeaves(N->right));
  //  printf("Look down left or right\n");
  }
}

Node *removeSubtree(Node *root, int value)
{
  if(root->left == NULL || root->right == NULL){

  }
  else if(root->left->value == value) {
      root->left= NULL;
      //free(root->left);
      //return root;
  }
  else if(root->right->value == value){
    root->right = NULL;
    //free(root->right);
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

Node *searchBST(Node *root, int value)
{

  if (root == NULL)
  {
    return NULL;
  }
  else if(root->value == value && root !=NULL){
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
int nodeDepth(Node *R, Node *N)
{
  int depth = 0;
  int found = 0;
/*
  while(found = 0){
    if(R->value == N->value){
      found = 1;
    }
    else if(R->value > N->value){
      R = N->left;
    }
    else{
      R = N->right;
    }

    }
    printf("%d found\n", found);
  }

 */ 
  if(R == NULL || N == NULL){
    return -1;
  }
  if(searchBST(R,N->value) == NULL){
    return -1;
  }
 
  
  if(R->value == N->value){
    return depth;
    
  }
  else if(R->value > N->value){     
     depth = nodeDepth(R->right,N) +1;
    // return depth;
   
  }
  else if(R->value < N->value){
   
    depth = nodeDepth(R->left,N) + 1;
   // return depth;
    
  }
 
}

/*
int main()
{
 // Node *a, *b;
  //a = addNode(NULL, 42);
  //a = addNode(a,55);
  //b = removeNode(a, 42);

 // assert(b == NULL);
  Node *a,*b,*d,*e,*f,*g,*h,*i,*j,*k,*l, *testa, *testb;
  Node*n;
   printf("Original test case 1: testing removeNode\n");
   
    a = addNode(NULL, 42);
    b = removeNode(a, 42);
    assert(b == NULL);
    printf("test passed\n");

    printf("Original test case 2: testing a 1 2 tree\n");
    a = addNode(NULL, 1);
    b = addNode(a, 2);
    displaySubtree(a);
    printf("-\nthe output should be\n1\n2\n-\n");

    printf("Original test case 3: testing numberLeaves\n");
    int c = numberLeaves(a);
    assert(c == 1);
    printf("test passed\n");

    printf("Original test case 4: testing nodeDepth\n");
    c = nodeDepth(a, b);
    assert(c == 1);
    printf("test passed\n");

    printf("Removing the entire tree to prevent memory leak\n");
    a = removeSubtree(a, 1);

    printf("--\nNow on to custom test cases (CTC)\n");

    printf("CTC1: Test if left side greater than right side\n");
    Node *n1, *n2, *n3;
    n1 = addNode(NULL, 5);
    n2 = addNode(n1, 6);
    n3 = addNode(n1, 4);
  //  printf("%d",n1->value);
    assert(n1->left->value == 6);
    assert(n1->right->value == 4);
    printf("test passed\n");

    printf("CTC2: Test the structure of RBST of 5 6 4 3\n");
    n2 = addNode(n1, 3);
    assert(n1->right->right->value == 3);
    printf("test passed\n");

    printf("CTC3: Test numberLeaves correct, n1 should have 2 leaves\n");
    // leaf node means node with no children
    assert(numberLeaves(n1) == 2);
    printf("test passed\n");



  
  d = addNode(a, 35);
  e = addNode(a, 60);
  f = addNode(a, 65);
  g = addNode(a, 66);
  h = addNode(a, 64);
  i = addNode(a, 55);
  j = addNode(a, 56);
  k = addNode(a, 54);
  l = addNode(a,36);

  testa = addNode(NULL,1);
  testb = addNode(testa,2);
  //printf("Test depth: %d\n", nodeDepth(a,b));

 // l = addNode(b,60);
//   a = addNode(NULL, 42);
 //  b = removeNode(a, 42);
 // a = addNode(NULL, 1);
 //  b = addNode(a, 2);
//  printf("%d depth\n", nodeDepth(a,j));
  // printf("a: %d b: %d", testa->value, testb->value);
    // printf(" b:%d",testa->value );
  //   printf(" b:%d",testa->left->value );
  //printf("Found: %d", numberLeaves(n));
 // n = removeNode(n,10);

 // a = removeNode(a,100);
 // a = removeSubtree(a,50);
   //n = removeNode(n,36);
   //a = removeSubtree(a,60);

//printf("%d\n" , a->value);
 // printf("%d\n" , a->left->value);
  //printf("%d\n" , a->left->value);
  // printf("%d\n" , a->right->value);
  //printf("%d: number of leaves", numberLeaves(a));

   printf("Break\n");
   displaySubtree(n1);
   //n = addNode(n,65);
   //displaySubtree(n);
  //free(n);

  return 0;
}

*/
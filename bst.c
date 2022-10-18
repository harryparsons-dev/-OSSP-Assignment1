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

  if (root->right->value == value)
  {

    if (root->right->left == NULL)
    {
    }
    else if (root->right->right == NULL)
    {
    }
    else if (root->right->left == NULL || root->right->right == NULL)
    {
    }
    else
    {
      int temp = root->right->value;
      root->right->left->right = root->right->right;
      root->right = root->right->left;
      printf("%d removed\n", temp);
    }
  }
  else if (root->left->value == value)
  {
  }
  else if (root->value == value)
  {
  }
  else if (root->value > value)
  {
    // move down to the left
  }
  else if (root->value < value)
  {
    // move down to the right
  }
  return root;
}

void displaySubtree(Node *N)
{

  if (N != NULL)
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
  return NULL;
}

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
  n = addNode(n, 10);
  b = addNode(NULL, 5);
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
   printf("%d depth\n", nodeDepth(n, b));
  // printf("Found: %d", numberLeaves(n));

  free(n);

  return 0;
}

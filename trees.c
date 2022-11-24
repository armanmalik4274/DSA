#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
  struct node* n=(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;
}

void preorder(struct node* root)
{
   if(root!=NULL)
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node* root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

void inorder(struct node*root)
{
 if(root!=NULL)
 {
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
 }
}

int main()
{
  struct node* p=createNode(4);
  struct node* p1=createNode(5);
  struct node* p2=createNode(6);
  struct node* p3=createNode(7);
  struct node* p4=createNode(8);
  struct node* p5=createNode(9);

  /*tree structure
       4
      /  \
     5    6
    / \  / \
   7   8    9

 */
  //linking the tree nodes
  p->left=p1;
  p->right=p2;
  p1->left=p3;
  p1->right=p4;
  p2->right=p5;

  printf("The preorder traversal of the given tree is:\n");
  preorder(p);
  printf("\n");

  printf("The postorder traversal of the given tree is:\n");
  postorder(p);
  printf("\n");

  printf("The inorder traversal of the given tree is:\n");
  inorder(p);
  return 0;
}

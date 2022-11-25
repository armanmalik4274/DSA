#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createnode(int data)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
};



void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root)
{
    static struct node* prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }

}


int main()
{
    struct node* p=createnode(20);
    struct node* p1=createnode(10);
    struct node* p2=createnode(30);
    struct node* p3=createnode(4);
    struct node* p4=createnode(15);
    struct node* p5=createnode(25);
    struct node* p6=createnode(70);

   /*
        20
       / \
      /   \
     10    30
    / \   / \
   4   15 25  70

   linking the nodes
   */
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->left=p5;
   p2->right=p6;



   printf("The inorder traversal of the given binary tree is:\n");
   inorder(p);
   printf("\n");

   printf("%d",isBST(p));
   printf("\n");

   return 0;
}

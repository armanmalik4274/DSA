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

struct node* search(struct node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
};

struct node* itersearch(struct node* root,int key)
{
 while(root!=NULL)
 {
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        root=root->left;
    }
    else{
        root=root->right;
    }
 }
 return NULL;
};

int main()
{
    struct node* p=createnode(1);
    struct node* p1=createnode(2);
    struct node* p2=createnode(3);
    struct node* p3=createnode(4);
    struct node* p4=createnode(5);
    struct node* p5=createnode(6);
    struct node* p6=createnode(7);

   /*
        1
       / \
      /   \
     2     3
    / \   / \
   4   5 6   7

   linking the nodes
   */
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->left=p5;
   p2->right=p6;


   printf("The element we want to search in BST is:\n");
   struct node* n=search(p,3);
   if(n!=NULL)
   {
       printf("Found: %d",n->data);
   }
   else{
    printf("Element not found in the given tree");
   }
   printf("\n");



   printf("The element we want to search in BST using iterative approach is:\n");
   struct node* k=itersearch(p,7);
   if(k!=NULL)
   {
       printf("Found: %d",k->data);
   }
   else{
    printf("Element not found in the given tree");
   }
   return 0;
}

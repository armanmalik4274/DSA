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

void insert(struct node* root,int key)
{
    struct node* prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("Cannot insert the key already same like root data");
            return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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


   /*
        20
       / \
      /   \
     10    30
    / \   / \
   4   15 25

   linking the nodes
   */
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->left=p5;

   insert(p,80);
   printf("%d",p->right->right->data);
   return 0;
}

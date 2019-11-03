#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int  item)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=item;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct node* insert(struct node* node,int key)
{
    if(node==NULL)
      return newNode(key) ;
    if(key < node->data)
    {
        node->left=insert(node->left,key);
    }  
    else if(key>node->data)
    {
        node->right=insert(node->right,key);
    }
    return node;
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int heght(struct node* root)
{
    if(root==NULL)
      return 0;
    int ldepth=heght(root->left);
    int rdepth=heght(root->right);
    if(ldepth>rdepth)
       return ldepth+1;
    return(rdepth+1);     
}
int main() {
    struct node* root=NULL;
    root=insert(root,20);
    insert(root,5);
    insert(root,12);
    insert(root,79);
    insert(root,78);
    insert(root,34);
    insert(root,8);
    inorder(root);
    printf("\n");
    printf("%d",heght(root));
}

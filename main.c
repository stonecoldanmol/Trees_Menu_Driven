//Tree driven program for c.
//strusture and DSA.
#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node* newnode(int data)
{
struct node *node=(struct node*)malloc(sizeof(struct node));

node->data=data;
node->left=NULL;
node->right=NULL;

return (node);
}

struct node* insert(struct node* node,int data)
{
if(node==NULL)
return (newnode(data));

else
{
if(data<=node->data)
node->left=insert(node->left,data);
else
node->right=insert(node->right,data);

return node;
}
}

void printInorder(struct node* node)
{
if(node==NULL)
return;

printInorder(node->left);
printf("%d ",node->data);
printInorder(node->right);

}

void printPostorder(struct node* node)
{
if(node==NULL)
return;

printPostorder(node->left);
printPostorder(node->right);
printf("%d ",node->data);
}

void printPreorder(struct node* node)
{
if(node==NULL)
return;

printf("%d ",node->data);
printPreorder(node->left);
printPreorder(node->right);
}

int minValue(struct node* node)
{
struct node* current=node;

while(current->left!=NULL)
{
current=current->left;
}

return(current->data);
}

int maxValue(struct node* node)
{
struct node* current=node;

while(current->right!=NULL)
{
current=current->right;
}

return(current->data);
}

void deleteTree(struct node* node)
{
if(node==NULL)
return;

deleteTree(node->left);
deleteTree(node->right);
printf("\n Deleted node:%d",node->data);
free(node);
}

struct node* search(struct node* node,int data)
{
if(node==NULL || node->data==data)
return node;

if(node->data<data)
return search(node->right,data);
else
return search(node->left,data);
}

int maxdepth(struct node* node)
{
if(node==NULL)
return 0;
else
{

int ldepth=maxdepth(node->left);
int rdepth=maxdepth(node->right);

if(ldepth>rdepth)
return (ldepth+1);
else
return (rdepth+1);

}
}

int size(struct node* node)
{
if(node==NULL)
return 0;

else
return (size(node->left)+1+size(node->right));
}

int main()
{
int choice;
struct node* root=newnode(1);
root->left=newnode(2);
root->right=newnode(3);
root->left->left=newnode(4);
root->left->right=newnode(5);
root->right->left=newnode(6);
while(1)
{


printf("\n\tMenu Driven\n");
printf("1.Insert\n");
printf("2.Inorder\n");
printf("3.Postorder\n");
printf("4.Preorder\n");
printf("5.Search\n");
printf("6.Delete\n");
printf("7.Max Depth\n");
printf("8.Max Value\n");
printf("9.Min Value\n");
printf("10.Size\n");
printf("11.Exit\n");


printf("Enter your choice:");
scanf("%d",&choice);


switch(choice)
{

case 1:
{
struct node* root=NULL;
printf("Insertion:\n");
root=insert(root,5);
insert(root,1);
insert(root,4);
insert(root,2);
insert(root,3);

printf("\nInorder Traversal\n");
printInorder(root);

}
break;

case 2:
{
printf("\nInorder traversal of Tree:\n");
printInorder(root);
}
break;

case 3:
{
printf("\nPostorder traversal of Tree:\n");
printPostorder(root);
}
break;
case 4:
{
printf("\nPreorder traversal of Tree:\n");
printPreorder(root);
}
break;

case 5:
{
int key;
struct node* root=NULL;
root=insert(root,1);
insert(root,2);
insert(root,3);
insert(root,4);
insert(root,5);

printf("\nEnter the value to search:");
scanf("%d",&key);

if(search(root,key))
printf("Search Found!");
else
printf("Not Found!");
}
break;

case 6:
{
deleteTree(root);
root=NULL;
printf("\nTree Deleted!");
}
break;

case 7:
{
struct node* root=NULL;
root=insert(root,5);
insert(root,1);
insert(root,4);
insert(root,2);
insert(root,3);

printf("Maximum depth of tree:%d",maxdepth(root));
}
break;

case 8:
{
struct node* root=NULL;
root=insert(root,5);
insert(root,1);
insert(root,4);
insert(root,2);
insert(root,3);

printf("Max Value of tree:%d",maxValue(root));
}
break;

case 9:
{
struct node* root=NULL;
root=insert(root,5);
insert(root,1);
insert(root,4);
insert(root,2);
insert(root,3);

printf("Min Value of tree:%d",minValue(root));
}
break;

case 10:
{
struct node* root=NULL;
root=insert(root,5);
insert(root,1);
insert(root,4);
insert(root,2);
insert(root,3);

printf("Size of tree:%d",size(root));
}
break;

case 11:
exit(0);
break;

default:
printf("\nInvalid Choice!");
}

}
getchar();
return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node* left;
    struct node* right;
} ;
typedef struct node* bin;
bin bin_init(){return NULL;}
void bin_push(struct node** tree,int data)
{
    bin temp=(bin)malloc(sizeof(struct node));
    temp->value=data;
    temp->left=NULL;
    temp->right=NULL;
    *tree=temp;
    return;
}

void bin_print_lr(struct node** tree)
{
    bin temp=*tree;
    if(temp==NULL){return;}
    printf("Data: %d\n",temp->value);
    bin_print_lr(&temp->left);
    bin_print_lr(&temp->right);
    return;
}
void bin_print_rl(struct node** tree)
{
    bin temp=*tree;
    if(temp==NULL){return;}
    printf("Data: %d\n",temp->value);
    bin_print_rl(&temp->right);
    bin_print_rl(&temp->left);
    return;
}
void bin_print_in(struct node** tree)
{
    bin temp=*tree;
    if(temp==NULL){return;}
    bin_print_in(&temp->right);
    printf("Data: %d\n",temp->value);
    bin_print_in(&temp->left);
    return;
}
void bin_print_pre(struct node** tree)
{
    bin temp=*tree;
    if(temp==NULL){return;}
    printf("Data: %d\n",temp->value);
    bin_print_pre(&temp->left);
    bin_print_pre(&temp->right);
    return;
}
void bin_print_post(struct node** tree)
{
    bin temp=*tree;
    if(temp==NULL){return;}
    bin_print_post(&temp->right);
    bin_print_post(&temp->left);
    printf("Data: %d\n",temp->value);
    return;
}
int bin_balanced(struct node** tree)
{

}

int main()
{
    bin test=bin_init();
    bin_push(&test,2);
    bin_push(&test->left,121);
    bin_push(&test->right,76);
    bin_push(&test->left->left,122);
    bin_push(&test->left->right,4);
    bin_push(&test->right->left ,76);
    bin_push(&test->right->right,21);
    bin_print_rl(&test);
    printf("\n");
    bin_print_lr(&test);
    printf("\n");
    bin_print_in(&test);
    printf("\n");
    bin_print_pre(&test);
    printf("\n");
    bin_print_post(&test);
}

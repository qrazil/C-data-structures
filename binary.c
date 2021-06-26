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
    bin temp=*tree;
    int left=0;
    int right=0;
    if(temp==NULL){return 1;}
    left=height(temp->left);
    right=height(temp->right);
    printf("left,right : %d,%d\n",left,right);
    if(abs(left-right)<=1 && bin_balanced(&temp->left) && bin_balanced(&temp->right)){return 1;}
    return 0;
}
int height(struct node* tree)
{
    if(tree==NULL){return 0;}
    return 1+max(height(tree->left),height(tree->right));
}
int max(int a,int b)
{
    return (a>=b)? a:b;
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
        printf("\n");
    int height=0;
    if(bin_balanced(&test))
    {
        printf("Tree is balanced\n");
    }
    else{printf("Tree is not balanced!\n");}
    printf("\n");
    bin test2=bin_init();
    bin_push(&test2,1);
    bin_push(&test2->left,2);
    bin_push(&test2->right,3);
    bin_push(&test2->left->left,4);
    bin_push(&test2->left->right,5);
    bin_push(&test2->left->left->left ,8);
    bin_print_lr(&test2);
    printf("\n");
    int height2=0;
    if(bin_balanced(&test2))
    {
        printf("Tree is balanced\n");
    }else{printf("Tree is not balanced!\n");}
    return 0;
}

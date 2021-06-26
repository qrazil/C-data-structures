#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    struct linked_list *addr;
    int data;
} ll;
typedef ll* link;

link ll_init()
{
    return NULL;
}
void ll_push(ll** list,int data)
{
    link temp=(link)malloc(sizeof(ll));
    temp->data=data;
    temp->addr=*list;
    *list=temp;
    return;
}
void ll_print(ll** list)
{
    link temp=*list;
    printf("Linked list:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        //printf("%d ",temp->addr);
        temp=temp->addr;
    }
    printf("\n");
    return;
}
int ll_pop(ll** list)
{
    int ret;
    link temp=*list;
    ret=temp->data;
    *list=temp->addr;
    free(temp);
    return ret;
}
void ll_insert(ll** list,int data,int position)
{
    link temp;
    int pos=0;
    temp=*list;
    while(temp!=NULL)
    {
        if(pos==position)
        {
            link temp_link=(link)malloc(sizeof(ll));
            temp_link->data=data;
            temp_link->addr=temp->addr;
            temp->addr=temp_link;
            return;
        }
        pos++;
        temp=temp->addr;
    }
    return;
}
void ll_delete(ll** list,int position)
{
    link temp1=*list;
    int pos=0;
    while(temp1!=NULL)
    {
        if(pos==position)
        {
            link temp2;
            temp2=temp1->addr->addr;
            free(temp1->addr);
            temp1->addr=temp2;
            return;
        }
        pos++;
        temp1=temp1->addr;
    }
    return;
}
void ll_clear(ll** list)
{
    while(*list!=NULL)
    {
        link temp=*list;
        *list=temp->addr;
        free(temp);
    }
    return;
}
//void ll_reverse(ll** list)
//{
//    link temp1=*list;
//    link temp2=ll_init();
//    while(temp1!=NULL)
//    {
//        ll_push(&temp2,temp1->data);
//        ll_pop(&temp1);
//    }
//    *list=temp2;
//    return;
//}
void ll_reverse(ll** list)
{
    link curr=*list;
    link prev=ll_init();
    link next=ll_init();
    while(curr!=NULL)
    {
        next=curr->addr;
        curr->addr=prev;
        prev=curr;
        curr=next;
    }
    *list=prev;
    return;
}
//int ll_find(ll** list,int data)
//{
//    link temp1=*list;
//    int pos=0;
//    while(temp1!=NULL)
//    {
//        if(temp1->data==data)
//        {
//            return pos;
//        }
//        temp1=temp1->addr;
//        pos++;
//    }
//    return -1;
//}
int ll_find(ll** list,int data)
{
    link temp1=*list;
    int ret=-1;
    int pos=0;
    while(temp1!=NULL)
    {
        if(temp1->data==data)
        {
            ret=pos;
        }
        temp1=temp1->addr;
        pos++;
    }
    if(ret!=-1){ret=pos-1-ret;}
    return ret;
}
int ll_at(ll** list,int position)
{
    link temp1=*list;
    int pos=0;
    while(temp1!=NULL)
    {
        if(pos==position)
        {
            return temp1->data;
        }
        temp1=temp1->addr;
        pos++;
    }
    return -1;
}
int ll_size(ll** list)
{
    link temp1=*list;
    int pos=0;
    while(temp1!=NULL)
    {
        temp1=temp1->addr;
        pos++;
    }
    return pos;
}
link ll_split(ll** list,int position)
{
    link temp=*list;
    link temp2;
    int pos=0;
    while(temp!=NULL)
    {
        if(pos==position-1)
        {
            temp2=temp->addr;
            temp->addr=NULL;
            return temp2;
        }
        temp=temp->addr;
        pos++;
    }
    return NULL;
}
void ll_merge(ll** list1,ll** list2)
{
    link temp1=*list1;
    link temp2=*list2;
    int pos=0;
    while(temp1!=NULL && temp2!=NULL)
    {
        ll_insert(&temp1,temp2->data,pos);
        temp1=temp1->addr->addr;
        ll_pop(&temp2);
    }
    return;
}
void ll_join(ll** list1,ll** list2)
{
    link temp1=*list1;
    link temp2=*list2;
    while(temp1!=NULL)
    {
        if(temp1->addr==NULL){temp1->addr=temp2;return;}
        temp1=temp1->addr;
    }
    return;
}
void ll_append(ll** list1,ll** list2)
{
    link temp1=*list1;
    link temp2=*list2;
    ll_reverse(&temp2);
    while(temp2!=NULL)
    {
        ll_push(&temp1,temp2->data);
        temp2=temp2->addr;
    }
    *list1=temp1;
    return;
}
link ll_copy(ll** list1)
{
    link temp1=ll_init();
    link temp2=*list1;
    while(temp2!=NULL)
    {
        ll_push(&temp1,temp2->data);
        temp2=temp2->addr;
    }
    ll_reverse(&temp1);
    return temp1;
}
int ll_mid(ll** list)
{
    link temp=*list;
    int size=ll_size(&temp);
    if(size%2==0){return (size/2)-1;}
    else{return size/2;}
    return -1;
}
//void ll_rotate(ll** list,int position)
//{
//    link temp1=*list;
//    link temp2=ll_split(&temp1,position);
//    ll_join(&temp2,&temp1);
//    *list=temp2;
//    return;
//}
void ll_rotate(ll** list,int position)
{
    link curr=*list;
    link head=ll_init();
    link tail=ll_init();
    int pos=0;
    tail=curr;
    while(curr!=NULL)
    {
        //printf("Data: %d ",curr->data);
        if(pos==position-1)
        {
            head=curr->addr;
            curr->addr=NULL;
            curr=head;
            pos++;
            continue;
        }
        if(curr->addr==NULL)
        {
            curr->addr=tail;
            break;
        }
        curr=curr->addr;
        pos++;
    }
    *list=head;
    return;
}
link ll_merge_sorted(ll** list1,ll** list2)
{
    link result = NULL;
    link lst1=*list1;
    link lst2=*list2;

	if (lst1 == NULL)
		return (lst2);
	else if (lst2 == NULL)
		return (lst1);

	if (lst1->data <= lst2->data) {
		result = lst1;
		result->addr = ll_merge_sorted(&lst1->addr, &lst2);
	}
	else {
		result = lst2;
		result->addr = ll_merge_sorted(&lst1, &lst2->addr);
	}
	return result;
}
void ll_sort(ll** list)
{
    link temp1=*list;
    link temp2;
    if((temp1==NULL) || (temp1->addr==NULL)) {return;}
    int size=ll_size(&temp1);
    temp2=ll_split(&temp1,size/2);
    ll_sort(&temp1);
    ll_sort(&temp2);
    temp1=ll_merge_sorted(&temp1,&temp2);
    *list=temp1;
    return;
}


int main()
{
    link list1=ll_init();
    link list2=ll_init();
    ll_push(&list2,21);
    ll_push(&list1,21);
    ll_push(&list1,51);
    ll_push(&list1,28);
    printf("Push :\n");
    ll_print(&list1);
    printf("POp :\n");
    ll_pop(&list1);
    ll_print(&list1);
    ll_push(&list1,28);
    ll_print(&list1);
    printf("Insert :\n");
    ll_insert(&list1,100,1);
    ll_print(&list1);
    printf("Delete :\n");
    ll_delete(&list1,1);
    ll_print(&list1);
    ll_push(&list1,1);
    ll_push(&list1,5);
    ll_push(&list1,282);
    ll_reverse(&list1);
    printf("Reversed list:\n");
    ll_print(&list1);
    int loc=ll_find(&list1,51);
    printf("Location of 51 is %d\n",loc);
    int loc2=ll_find(&list1,100);
    printf("Location of 100 is %d\n",loc2);
    ll_rotate(&list1,3);
    printf("Rotated list at location 3:\n");
    ll_print(&list1);
    link test=ll_init();
    test=ll_split(&list1,3);
    printf("Split list at location 3:\n");
    ll_print(&test);
    ll_print(&list1);
    ll_merge(&list1,&test);
    printf("Merged list:\n");
    ll_print(&list1);
    ll_join(&list1,&list2);
    printf("JOined list:\n");
    ll_print(&list1);
    link list3=ll_copy(&list1);
    printf("copied list:\n");
    ll_print(&list3);
    link list4=ll_init();
    ll_push(&list4,84);
    ll_push(&list4,23);
    ll_push(&list4,15);
    ll_push(&list4,94);
    ll_push(&list4,34);
    ll_print(&list4);
    ll_append(&list1,&list4);
    printf("Appended list:\n");
    ll_print(&list1);
    ll_sort(&list1);
    printf("Sorted List:\n");
    ll_print(&list1);
    int size=ll_size(&list1);
    printf("Size of list 1 is %d\n",size);
    int mid=ll_mid(&list1);
    printf("Mid element is %d\n",ll_at(&list1,mid));
    ll_clear(&list1);
    ll_print(&list1);
    return 0;
}

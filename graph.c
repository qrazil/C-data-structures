#include<stdio.h>
#include<stdlib.h>
struct graph_node
{
    int* value;
    int connections;
    struct graph_node** connecting_nodes;
};
struct graph_list
{
    int size;
    struct graph_node* list;
};
typedef struct graph_list* graph;
typedef struct graph_node* node;
graph graph_init(int size_of_graph)
{
    graph new_graph=(graph)malloc(sizeof(struct graph_list));
    new_graph->size=size_of_graph;
    new_graph->list=(node)calloc(size_of_graph,sizeof(struct graph_node));
    return new_graph;
}
void add_node(struct graph_list** graph_in_use,int main_node,int connecting_node,int value)
{
    node temp1,temp2;
    int n,i,place;
    graph main_graph=*graph_in_use;
    temp1=&main_graph->list[main_node];
    for(i=0;i<main_graph->size;i++)
    {
        if(i==connecting_node)
        {
            temp2=&main_graph->list[i];
            break;
        }
    }
    if(temp1->connecting_nodes==NULL)
    {
        temp1->connecting_nodes=(node*)malloc(sizeof(node));
        temp1->value=(int*)malloc(sizeof(int));
        temp1->connections=1;
    }
    else
    {
        temp1->connections++;
        temp1->connecting_nodes=(node*)realloc(temp1->connecting_nodes,(temp1->connections)*sizeof(node));
        temp1->value=(int*)realloc(temp1->value,(temp1->connections)*sizeof(int));
    }
    temp1->connecting_nodes[temp1->connections-1]=temp2;
    temp1->value[temp1->connections-1]=value;
    main_graph->list[main_node]=*temp1;
    return;
}
void print_graph(struct graph_list** graph_in_use)
{
    graph temp;
    temp=*graph_in_use;
    int i,j;
    for(i=0;i<temp->size;i++)
    {
        if(temp->list[i].connecting_nodes!=NULL)
        {
        for(j=0;j<temp->list[i].connections;j++)
            {
                printf("Graph: %d %d %d %d\n",i,&temp->list[i],temp->list[i].connecting_nodes[j],temp->list[i].value[j]);
            }
        }
        else{printf("Graph: %d %d %d %d\n",i,&temp->list[i],temp->list[i].connecting_nodes,temp->list[i].value);}
    }
    return;
}



struct ll_graph_node
{
    int self_node;
    int* value;
    int connections;
    struct ll_graph_node** connecting_nodes;
};
typedef struct ll_graph_node* ll_node;
ll_node node_init(int main)
{
    ll_node temp1;
    temp1=(ll_node)malloc(sizeof(struct ll_graph_node));
    temp1->self_node=main;
    temp1->connecting_nodes=NULL;
    temp1->connections=0;
    temp1->value=0;
    return temp1;
}
void add_connections(struct ll_graph_node** main,struct ll_graph_node** next,int value)
{
    ll_node temp1,temp2;
    temp1=*main;
    temp2=*next;
    if(temp1->connecting_nodes==NULL)
    {
        temp1->connecting_nodes=(ll_node*)malloc(sizeof(ll_node));
        temp1->value=(int*)malloc(sizeof(int));
        temp1->connections=1;
    }
    else
    {
        temp1->connections++;
        temp1->connecting_nodes=(ll_node*)realloc(temp1->connecting_nodes,(temp1->connections)*sizeof(ll_node));
        temp1->value=(int*)realloc(temp1->value,(temp1->connections)*sizeof(int));
    }
    temp1->connecting_nodes[temp1->connections-1]=temp2;
    temp1->value[temp1->connections-1]=value;
    return;
}
void print_connections(struct ll_graph_node** main)
{
    ll_node temp=*main;
    int i,j;
    for(i=0;i<temp->connections;i++)
    {
        if(temp->connecting_nodes!=NULL)
        {
            printf("Graph: Main :%d Next :%d Value :%d\n",temp->self_node,temp->connecting_nodes[i]->self_node,temp->value[i]);
        }
        else{printf("Graph: Main :%d Next :%d Value :%d\n",temp->self_node,temp->connecting_nodes[0]->self_node,temp->value);}
    }

    return;
}





int array_check(node* array,int size,node check)
{
    //printf("Checking Array:\n");
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i]==check)
        {
            return 1;
        }
    }
    return 0;
}
void print_array(node* array,int size)
{
    //printf("Printing array:\n");
    int i;
    for(i=0;i<size;i++)
    {
        printf("element %d : %d \n",i,array[i]);
    }
    return ;
}
void dfs(struct graph_list** graph_in_use,int main_node,int connecting_node)
{
    graph temp_graph;
    int i,j,sum;
    temp_graph=*graph_in_use;
    node collection[temp_graph->size];
    node main=&temp_graph->list[main_node];
    node temp_node=&temp_graph->list[main_node];
    j=0;
    sum=0;
    while(temp_node!=NULL)
    {
        //printf("test: %d %d %d\n",collection[j],j,temp_node);
        //print_array(collection,j);
        if(array_check(collection,j,temp_node)){printf("There is no connection between %d and %d \n\n\n",main,&temp_graph->list[connecting_node]);break;}
        collection[j]=temp_node;
        for(i=0;i<temp_node->connections;i++)
        {
            if(temp_node->connecting_nodes[i]==&temp_graph->list[connecting_node])
            {
                sum+=temp_node->value[i];
                printf("Connection: %d -> %d || %d  %d\n\n\n",temp_node,temp_node->connecting_nodes[i],temp_node->value[i],sum);
                return;
            }
        }
        sum+=temp_node->value[temp_node->connections-1];
        printf("Connection: %d -> %d || %d  %d\n",temp_node,temp_node->connecting_nodes[temp_node->connections-1],temp_node->value[temp_node->connections-1],sum);
        temp_node=temp_node->connecting_nodes[temp_node->connections-1];
        j++;
    }
    return;
}

void bfs(struct graph_list** graph_in_use,int main_node,int connecting_node)
{
    graph temp_graph;
    int i,j,sum;
    temp_graph=*graph_in_use;
    node collection[temp_graph->size];
    node main=&temp_graph->list[main_node];
    node temp_node=&temp_graph->list[main_node];
    j=0;
    sum=0;
    while(temp_node!=NULL)
    {
        //printf("test: %d %d %d\n",collection[j],j,temp_node);
        //print_array(collection,j);
        if(array_check(collection,j,temp_node)){printf("There is no connection between %d and %d \n\n\n",main,&temp_graph->list[connecting_node]);break;}
        collection[j]=temp_node;
        for(i=0;i<temp_node->connections;i++)
        {
            if(temp_node->connecting_nodes[i]==&temp_graph->list[connecting_node])
            {
                sum+=temp_node->value[i];
                printf("Connection: %d -> %d || %d  %d\n\n\n",temp_node,temp_node->connecting_nodes[i],temp_node->value[i],sum);
                return;
            }
            printf("Connection: %d -> %d || %d  %d\n",temp_node,temp_node->connecting_nodes[temp_node->connections-1],temp_node->value[temp_node->connections-1],sum);
        }
        sum+=temp_node->value[temp_node->connections-1];
        printf("Connection: %d -> %d || %d  %d\n",temp_node,temp_node->connecting_nodes[temp_node->connections-1],temp_node->value[temp_node->connections-1],sum);
        temp_node=temp_node->connecting_nodes[temp_node->connections-1];
        j++;
    }
    return;
}
int main()
{
    graph GRAPH1;
    GRAPH1=graph_init(7);
    printf("Size of graph is %d\n",GRAPH1->size);
    add_node(&GRAPH1,0,1,1);
    add_node(&GRAPH1,1,2,3);
    add_node(&GRAPH1,2,0,1);
    add_node(&GRAPH1,2,3,2);
    add_node(&GRAPH1,3,2,4);
    add_node(&GRAPH1,4,6,5);
    add_node(&GRAPH1,5,4,1);
    add_node(&GRAPH1,6,5,6);
    print_graph(&GRAPH1);
//    ll_node node1=node_init(1);
//    ll_node node2=node_init(2);
//    ll_node node3=node_init(3);
//    ll_node node4=node_init(4);
//    add_connections(&node1,&node2,1);
//    add_connections(&node2,&node1,3);
//    add_connections(&node3,&node1,1);
//    add_connections(&node3,&node4,4);
//    print_connections(&node1);
//    print_connections(&node2);
//    print_connections(&node3);
    printf("BFS:\n");
    bfs(&GRAPH1,1,2);
    bfs(&GRAPH1,0,3);
    bfs(&GRAPH1,0,4);
    printf("DFS:\n");
    dfs(&GRAPH1,1,2);
    dfs(&GRAPH1,0,3);
    dfs(&GRAPH1,0,4);
    return 0;
}

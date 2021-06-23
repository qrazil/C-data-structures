#include<stdioi.h>
#include<stdlib.h>
struct graph
{
    struct con* list;
};
struct con
{
    struct con* dest;
    int value;
};
typedef struct con* node
void graph_push(struct con** graph_node,int data)
{
    node temp_node=(node)malloc(sizeof(struct con))
    temp_node=
}

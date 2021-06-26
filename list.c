#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;
    int *list=(int*)malloc(sizeof(int)*1);
    for(i=0;i<100;i++)
    {
        *(list+i)=i;
        printf("%d %d\n",i+1,*(list+i));
        list=(int*)realloc(list,sizeof(int)*i+1);
    }
    for (j=0;j<100;j++){
        printf("%d\n",*(list+j));
    }

    char name[20];
    printf("Enter name: \n");
    scanf("%s",name);
    char *new_name=(char*)malloc(10);
    strcpy(new_name,name);
    printf("Name is %s\n",new_name);
    strcat(new_name,name);
    printf("Name is %s\n",new_name);
    strcat(new_name,name);
    printf("Name is %s\n",new_name);
    return 0;
}

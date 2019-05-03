#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//头部方式插入节点

struct Node1
{
    char name[30];
    struct Node1 *next;
};

typedef struct Node1 Node;


int main()
{
    Node *pHead = NULL;
    while(1)
    {
        printf("请输入学生,q(退出系统),p(打印)\n");
        char name[30];
        scanf("%s",name);

        //退出系统
        if(strcmp(name,"q")==0)
        {
           printf("退出系统\n");
           break;
        }

        //打印信息
        if(strcmp(name,"p")==0)
        {
           Node *pNode = pHead;
           while(pNode !=NULL)
           {
               printf("%s     ",pNode->name);
               pNode = pNode->next;
           }
           printf("\n");
        }

        else
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            pNode ->next = pHead;   //让新节点的下一个指向 之前链表的头节点
            strcpy(pNode->name,name);
            pHead = pNode;
        }
    }


}

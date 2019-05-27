#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: 刘旭芝
 * Date: 2019.05.27
 * 向双向链表头部插入新的节点(头插法)
*************************************************************/


//定义一个节点
typedef struct Node1
{
    char name[30];
    struct Node1 *prev;
    struct Node1 *next;
}Node;

int main()
{
    Node *pHead = NULL;
    char name[30];
    while(1)
    {
        printf("请输入学生姓名，q(退出)，p(打印)\n");
        scanf("%s",name);
        if(strcmp(name,"q") == 0)
        {
            printf("已退出系统");
            break;
        }
        else if(strcmp(name,"p") == 0)
        {
            Node *pTemp = pHead;

            //正向打印
            while(pTemp)
            {
                printf("%s  ",pTemp ->name);
                pTemp = pTemp -> next;
            }
            printf("\n");
        }
        else    //添加节点
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            strcpy(pNode ->name,name);
            pNode ->prev = NULL;
            pNode ->next = NULL;

            //初始链表为空的情况
            if(pHead == NULL)
            {
                pHead = pNode;
            }
            else
            {
                pNode ->next = pHead;   //新的节点的next指向原头节点
                pHead -> prev = pNode;  //原头节点的prev指向新节点
                pHead = pNode;          //头节点指向新的节点
            }
        }
    }
}


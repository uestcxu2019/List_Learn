#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: 刘旭芝
 * Date: 2019.05.09
 * 向单向循环链表头部插入新的节点
 *
 *
**/


//定义一个节点
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;


int main()
{
    Node *pHead = NULL;
    Node *pTail = NULL;

    while(1)
    {
        printf("请输入学生姓名:q(退出系统)，p(打印)\n");
        char name[30];
        scanf("%s",name);
        if(strcmp(name,"q") == 0)
        {
            printf("已退出系统");
            break;
        }
        //打印链表
        if(strcmp(name,"p") == 0)
        {
            Node *pTemp = pHead;
            //遍历链表
            do
            {
                if(pTemp != NULL)
                {
                    printf("%s  ",pTemp ->name);
                    pTemp = pTemp ->next;
                }
            }
            while(pTemp != pHead);
            printf("\n");
        }
        //节点插入
        else
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            strcpy(pNode ->name,name);

            //判定是否是头节点
            if(pHead == NULL)
            {
                pHead = pTail = pNode;
                pTail ->next = pHead;
            }
            else
            {
                pNode ->next = pHead;   //让新节点的next指向原头节点
                pHead = pNode;  //让新节点作为新的头节点
                pTail ->next = pHead;   //让尾节点的next指向新头节点
            }
        }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: 刘旭芝
 * Date: 2019.05.16
 * 删除单向循环链表头部节点
 *          步骤:
 *              1.遍历链表，找到最后一个节点
 *              2.删除头部节点(如果是malloc内存，要free)
 *              3.头指针指向新头节点，将尾节点的next指向新头节点
*************************************************************/


//定义一个节点
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;

//链表创建函数,传入参数为链表节点个数
Node *CreateList(int n)
{
    Node *phead = NULL;
    Node *pTail = NULL;
    int i = 0;
    for(i = 0;i < n;i++)
    {
        Node *pNode = (Node *)malloc(sizeof(Node));
        sprintf(pNode->name,"学生%d",i+1);

        if(phead == NULL)
        {
            phead = pTail = pNode;
            pNode ->next = phead;
        }
        else
        {
            pTail ->next = pNode;
            pTail = pNode;
            pTail ->next = phead;
        }

    }
    return phead;
}


//打印链表
Node *PrintList(Node *phead)
{
    Node *pTemp = phead;
    do
    {
        if(pTemp != NULL)
        {
            printf("%s   ",pTemp ->name);
            pTemp = pTemp ->next;
        }
    }
    while(pTemp != phead);
    printf("\n");
    return phead;
}


//删除链表头部节点函数，传入参数为链表头节点指针
Node *DeleteList(Node *phead)
{
    Node *pTemp = phead;
    //链表只有一个节点的情况
    if(phead ->next == phead)
    {
        free(phead);
        printf("唯一节点已删除,当前链表为空链表\n");
        return NULL;
    }

    //遍历链表，找到尾部节点
    while(pTemp ->next != phead)
    {
        pTemp = pTemp ->next;
    }
    printf("找到尾节点是:   %s\n",pTemp->name);

    //将原链表的第二个节点作为新的节点
    phead = phead ->next;

    //删除头部节点(尾节点指向的下一个节点即为原头节点)
    free(pTemp ->next);

    //尾节点的next指向新的头节点
    pTemp ->next = phead;

    return phead;
}

int main()
{
    Node *p = NULL;
    p = CreateList(1);
    p = PrintList(p);
    p = DeleteList(p);
    p = PrintList(p);
}


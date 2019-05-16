#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: 刘旭芝
 * Date: 2019.05.16
 * 删除单向循环链表尾部节点
 *          步骤:
 *              1.遍历链表，找到尾部节点的前一个节点
 *              2.删除尾部节点(如果是malloc内存，要free)
 *              3.将新尾部节点的next指向头节点
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



//删除链表尾部节点函数
Node *DeleteList(Node *phead)
{
    //找到链表的倒数第二个节点
    Node *pNode = phead;

    //链表只有一个节点的情况
    if(phead == NULL)
    {
        free(phead);
        return NULL;
    }
    while(pNode ->next ->next != phead)
    {
        pNode = pNode ->next;
    }
    printf("找到倒数第二个节点是:   %s\n",pNode->name);

    //删除最后一个节点
    free(pNode ->next);
    pNode ->next = phead;

    return phead;
}

int main()
{
    Node *p = NULL;
    p = CreateList(3);
    p = PrintList(p);
    p = DeleteList(p);

    p = PrintList(p);
    p = DeleteList(p);
    p = PrintList(p);

    p = DeleteList(p);
    p = PrintList(p);
}


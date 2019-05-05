#include "list.h"

/****************************************************************************
**  Author: 刘旭芝
**  Date  : 2019.05.05
**
**  步骤:   1.保存头节点指向下一节点的地址
**          2.删除节点(如果是malloc分配的内存，要使用free函数)
**          3.将pHead指向保留的节点地址
****************************************************************************/


//创建链表,拥有N个节点。使用尾插法,即创建的节点默认作为尾节点
Node *CreateList(int N)
{
   Node *pHead = NULL;
   Node *pTail = NULL;
   int i;
   for(i = 0;i < N;i++)
   {
       Node *pNode = (Node *)malloc(sizeof(Node));
       pNode ->next = NULL;
       sprintf(pNode->name,"学生%d",i+1);
       if(pHead == NULL)
       {
           pHead = pNode;
       }
       else
       {
           pTail ->next = pNode;
       }
       pTail = pNode;
   }
    return pHead;
}


//打印链表
void PrintList(Node *pHead)
{
    while(pHead != NULL)
    {
        printf("%s    ",pHead->name);
        pHead = pHead->next;
    }
    printf("\n");
}


//删除链表头部节点
Node *DeleteList(Node *phead)
{
    //判定链表是否只有一个节点
    if(phead ->next == NULL)
    {
        return NULL;
    }
    //定义一个临时变量用于保存头节点指向下一个节点的地址
    Node *pTemp = phead ->next;
    free(phead);

    return pTemp;
}

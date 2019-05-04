#include "list.h"

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


//删除链表尾部节点,需要找到尾部节点以及倒数第二个节点
Node *DeleteList(Node *phead)
{
    //判定链表是否只有一个节点
    if(phead->next == NULL)
    {
        printf("当前链表只有一个节点\n");
        free(phead);
        return NULL;
    }
    Node *pTemp = phead;
    while(phead ->next ->next != NULL)
    {
        phead = phead ->next;
    }
    printf("当前节点是:%s\n",phead ->name);
    //删除最后一个节点
    free(phead ->next);

    //将倒数第二个节点作为最后一个节点
    phead ->next = NULL;
    return pTemp;
}

#include "list.h"

/****************************************************************************
**  Author: 刘旭芝
**  Date  : 2019.05.06
**
**  步骤:   1.找到删除节点的上一个节点地址
**          2.删除节点(如果是malloc分配的内存，要使用free函数)
**          3.将上一个节点的next指向删除节点的next地址
****************************************************************************/



/****************************************************************************
**  描   述:链表创建函数,采用尾插法方式
**  参   数:n:链表的节点个数
**  返回值: 无
****************************************************************************/
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


/****************************************************************************
**  描   述:打印链表,从链表头部节点开始遍历打印
**  参   数:pHead:链表的头节点
**  返回值: 无
****************************************************************************/
void PrintList(Node *pHead)
{
    while(pHead != NULL)
    {
        printf("%s    ",pHead->name);
        pHead = pHead->next;
    }
    printf("\n");
}


/****************************************************************************
**  描   述:链表节点删除函数,从链表中部节点删除,
**  参   数:pHead:链表的头节点，name:要删除节点的名称
**  返回值: 返回链表头节点
****************************************************************************/
Node *DeleteList(Node *phead,const char *name)
{
    Node *pTemp = phead;
    Node *pLast = NULL;     //保存上一节点地址

    while(pTemp != NULL)
    {
        if(strcmp(pTemp ->name,name) == 0)
        {
            break;
        }
        pLast = pTemp;
        pTemp = pTemp ->next;
    }

    if(pTemp == NULL)
    {
        printf("未找到此节点!\n");
    }
    else
    {
        printf("找到要删除的节点，此节点是:  %s \n",pTemp ->name);
        printf("找到要删除的节点的前一个节点，此节点是:  %s \n",pLast ->name);

        if(pLast == NULL)//说明删除的是头节点
        {
            phead = pTemp ->next;
            free(pTemp);
        }
        else
        {
            pLast ->next = pTemp ->next;
            //删除当前节点
            free(pTemp);
        }
    }
    return phead;
}

#include "list.h"

/****************************************************************************
**  Author: ����֥
**  Date  : 2019.05.05
**
**  ����:   1.����ͷ�ڵ�ָ����һ�ڵ�ĵ�ַ
**          2.ɾ���ڵ�(�����malloc������ڴ棬Ҫʹ��free����)
**          3.��pHeadָ�����Ľڵ��ַ
****************************************************************************/


//��������,ӵ��N���ڵ㡣ʹ��β�巨,�������Ľڵ�Ĭ����Ϊβ�ڵ�
Node *CreateList(int N)
{
   Node *pHead = NULL;
   Node *pTail = NULL;
   int i;
   for(i = 0;i < N;i++)
   {
       Node *pNode = (Node *)malloc(sizeof(Node));
       pNode ->next = NULL;
       sprintf(pNode->name,"ѧ��%d",i+1);
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


//��ӡ����
void PrintList(Node *pHead)
{
    while(pHead != NULL)
    {
        printf("%s    ",pHead->name);
        pHead = pHead->next;
    }
    printf("\n");
}


//ɾ������ͷ���ڵ�
Node *DeleteList(Node *phead)
{
    //�ж������Ƿ�ֻ��һ���ڵ�
    if(phead ->next == NULL)
    {
        return NULL;
    }
    //����һ����ʱ�������ڱ���ͷ�ڵ�ָ����һ���ڵ�ĵ�ַ
    Node *pTemp = phead ->next;
    free(phead);

    return pTemp;
}

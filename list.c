#include "list.h"

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


//ɾ������β���ڵ�,��Ҫ�ҵ�β���ڵ��Լ������ڶ����ڵ�
Node *DeleteList(Node *phead)
{
    //�ж������Ƿ�ֻ��һ���ڵ�
    if(phead->next == NULL)
    {
        printf("��ǰ����ֻ��һ���ڵ�\n");
        free(phead);
        return NULL;
    }
    Node *pTemp = phead;
    while(phead ->next ->next != NULL)
    {
        phead = phead ->next;
    }
    printf("��ǰ�ڵ���:%s\n",phead ->name);
    //ɾ�����һ���ڵ�
    free(phead ->next);

    //�������ڶ����ڵ���Ϊ���һ���ڵ�
    phead ->next = NULL;
    return pTemp;
}

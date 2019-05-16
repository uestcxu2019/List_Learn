#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: ����֥
 * Date: 2019.05.16
 * ɾ������ѭ������β���ڵ�
 *          ����:
 *              1.���������ҵ�β���ڵ��ǰһ���ڵ�
 *              2.ɾ��β���ڵ�(�����malloc�ڴ棬Ҫfree)
 *              3.����β���ڵ��nextָ��ͷ�ڵ�
*************************************************************/


//����һ���ڵ�
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;

//����������,�������Ϊ����ڵ����
Node *CreateList(int n)
{
    Node *phead = NULL;
    Node *pTail = NULL;
    int i = 0;
    for(i = 0;i < n;i++)
    {
        Node *pNode = (Node *)malloc(sizeof(Node));
        sprintf(pNode->name,"ѧ��%d",i+1);

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


//��ӡ����
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



//ɾ������β���ڵ㺯��
Node *DeleteList(Node *phead)
{
    //�ҵ�����ĵ����ڶ����ڵ�
    Node *pNode = phead;

    //����ֻ��һ���ڵ�����
    if(phead == NULL)
    {
        free(phead);
        return NULL;
    }
    while(pNode ->next ->next != phead)
    {
        pNode = pNode ->next;
    }
    printf("�ҵ������ڶ����ڵ���:   %s\n",pNode->name);

    //ɾ�����һ���ڵ�
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


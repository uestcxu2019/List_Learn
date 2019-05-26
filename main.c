#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: ����֥
 * Date: 2019.05.16
 * ɾ������ѭ������ͷ���ڵ�
 *          ����:
 *              1.���������ҵ����һ���ڵ�
 *              2.ɾ��ͷ���ڵ�(�����malloc�ڴ棬Ҫfree)
 *              3.ͷָ��ָ����ͷ�ڵ㣬��β�ڵ��nextָ����ͷ�ڵ�
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


//ɾ������ͷ���ڵ㺯�����������Ϊ����ͷ�ڵ�ָ��
Node *DeleteList(Node *phead)
{
    Node *pTemp = phead;
    //����ֻ��һ���ڵ�����
    if(phead ->next == phead)
    {
        free(phead);
        printf("Ψһ�ڵ���ɾ��,��ǰ����Ϊ������\n");
        return NULL;
    }

    //���������ҵ�β���ڵ�
    while(pTemp ->next != phead)
    {
        pTemp = pTemp ->next;
    }
    printf("�ҵ�β�ڵ���:   %s\n",pTemp->name);

    //��ԭ����ĵڶ����ڵ���Ϊ�µĽڵ�
    phead = phead ->next;

    //ɾ��ͷ���ڵ�(β�ڵ�ָ�����һ���ڵ㼴Ϊԭͷ�ڵ�)
    free(pTemp ->next);

    //β�ڵ��nextָ���µ�ͷ�ڵ�
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


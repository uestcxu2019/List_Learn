#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: ����֥
 * Date: 2019.05.09
 * ����ѭ������ͷ�������µĽڵ�
 *
 *
**/


//����һ���ڵ�
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
        printf("������ѧ������:q(�˳�ϵͳ)��p(��ӡ)\n");
        char name[30];
        scanf("%s",name);
        if(strcmp(name,"q") == 0)
        {
            printf("���˳�ϵͳ");
            break;
        }
        //��ӡ����
        if(strcmp(name,"p") == 0)
        {
            Node *pTemp = pHead;
            //��������
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
        //�ڵ����
        else
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            strcpy(pNode ->name,name);

            //�ж��Ƿ���ͷ�ڵ�
            if(pHead == NULL)
            {
                pHead = pTail = pNode;
                pTail ->next = pHead;
            }
            else
            {
                pNode ->next = pHead;   //���½ڵ��nextָ��ԭͷ�ڵ�
                pHead = pNode;  //���½ڵ���Ϊ�µ�ͷ�ڵ�
                pTail ->next = pHead;   //��β�ڵ��nextָ����ͷ�ڵ�
            }
        }
    }
}


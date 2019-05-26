#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: ����֥
 * Date: 2019.05.26
 * ��˫������β�������µĽڵ�(β�巨)
*************************************************************/


//����һ���ڵ�
typedef struct Node1
{
    char name[30];
    struct Node1 *prev;
    struct Node1 *next;
}Node;

int main()
{
    Node *pHead = NULL;
    Node *pTail = NULL;
    char name[30];
    while(1)
    {
        printf("������ѧ��������q(�˳�)��p(��ӡ)\n");
        scanf("%s",name);
        if(strcmp(name,"q") == 0)
        {
            printf("���˳�ϵͳ");
            break;
        }
        else if(strcmp(name,"p") == 0)
        {
            Node *pTemp = pHead;

            //�����ӡ
            while(pTemp)
            {
                printf("%s  ",pTemp ->name);
                pTemp = pTemp -> next;
            }
            printf("\n");

            //�����ӡ
            pTemp = pTail;
            while(pTemp)
            {
                printf("%s  ",pTemp ->name);
                pTemp = pTemp -> prev;
            }
            printf("\n");
        }
        else    //��ӽڵ�
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            strcpy(pNode ->name,name);
            pNode ->prev = NULL;
            pNode ->next = NULL;

            //��ʼ����Ϊ��
            if(pHead == NULL)
            {
                pHead = pTail = pNode;
            }
            else
            {
                pTail ->next = pNode;
                pNode -> prev = pTail;
                pTail = pNode;
            }
        }
    }
}


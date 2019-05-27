#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: ����֥
 * Date: 2019.05.27
 * ��˫������ͷ�������µĽڵ�(ͷ�巨)
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
        }
        else    //��ӽڵ�
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            strcpy(pNode ->name,name);
            pNode ->prev = NULL;
            pNode ->next = NULL;

            //��ʼ����Ϊ�յ����
            if(pHead == NULL)
            {
                pHead = pNode;
            }
            else
            {
                pNode ->next = pHead;   //�µĽڵ��nextָ��ԭͷ�ڵ�
                pHead -> prev = pNode;  //ԭͷ�ڵ��prevָ���½ڵ�
                pHead = pNode;          //ͷ�ڵ�ָ���µĽڵ�
            }
        }
    }
}


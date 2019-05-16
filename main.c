#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: ����֥
 * Date: 2019.05.06
 * ����ѭ������β�������µĽڵ�
 *
 *  ���裻
 *      1.�û�ÿ����һ�Σ���̬����һ���ڵ�
 *      2.���ڵ������ݸ�ֵȻ��ͷ��ָ��ָ���½ڵ㣬��β��ָ���nextָ���½ڵ�
 *      3.���½ڵ��nextָ��ԭ����ͷ���ڵ�,
**/

//����һ���ڵ�ṹ��
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;


int main(void)
{
    Node *pHead = NULL; //����һ����ʼ��Ϊ�յ�ͷ�ڵ㣬���ڱ���
    Node *pTail = NULL; //����һ����ʼ��Ϊ�յ�β�ڵ㣬���ڲ����½ڵ�
    char name[30];

    while(1)
    {
        printf("������ѧ������: q(�˳�ϵͳ),p(��ӡ)\n");
        scanf("%s",name);

        //�˳�ϵͳ
        if(strcmp(name,"q") == 0)
        {
            printf("���˳�ϵͳ\n");
            break;
        }
        if(strcmp(name,"p") == 0)
        {
            Node *pNode = pHead;

            do
            {
                if(pNode != NULL)
                {
                    printf("%s   ",pNode ->name);
                   pNode = pNode ->next;
                }
            }
            while(pNode != pHead);
            printf("\n");
        }
        else
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            pNode ->next = pHead;
            strcpy(pNode ->name,name);
            if(pHead == NULL)//�ж�Ϊ������
            {
                pHead = pTail = pNode;
                pNode ->next =pHead;    //�γ�һ���ػ�
            }
            else
            {
                pTail ->next = pNode;
                pNode ->next = pHead;
                pTail = pNode;
            }
        }

    }
}


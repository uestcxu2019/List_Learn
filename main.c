#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: ����֥
 * Date: 2019.05.26
 * �����Ӵ�˫����������һ����򵥵�˫����������������ӡ��Ϣ
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
    //���������ڵ�
    Node stu1,stu2,stu3;

    //�ڵ㸳ֵ
    strcpy(stu1.name,"ѧ��A");
    strcpy(stu2.name,"ѧ��B");
    strcpy(stu3.name,"ѧ��C");

    //������һ���򵥵�˫������
    stu1.prev = NULL;
    stu1.next = &stu2;

    stu2.prev = &stu1;
    stu2.next = &stu3;

    stu3.prev = &stu2;
    stu3.next = NULL;


    //�����ӡ����
    Node *phead = &stu1;
    while(phead)
    {
        printf("%s  ",phead ->name);
        phead = phead ->next;
    }
    printf("\n");

    //�����ӡ����
    Node *pTail = &stu3;
    while(pTail)
    {
       printf("%s  ",pTail ->name);
       pTail = pTail ->prev;
    }

    return 0;
}


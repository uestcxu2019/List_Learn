#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: ����֥
 * Date: 2019.05.06
 * �����Ӵ�����ѭ������
*/


//����һ���ڵ�
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;


int main()
{
    //���������ڵ�
    Node Stu1,Stu2,Stu3;

    //����һ���򵥵ĵ���ѭ������
    Stu1.next = &Stu2;
    Stu2.next = &Stu3;
    Stu3.next = &Stu1;

    //�������Ա��ֵ
    strcpy(Stu1.name,"ѧ��1");
    strcpy(Stu2.name,"ѧ��2");
    strcpy(Stu3.name,"ѧ��3");

    //��ӡ����,����ͨ���ж����һ��nextָ��ΪNULL���ж�
     Node *pHead = &Stu1;
     Node *pNode = pHead;
     do
     {
         if(pNode != NULL)
         {
             printf("%s   ",pNode ->name);
         pNode = pNode ->next;
         }
         else
         {
             printf("����һ��������\n");
         }
     }
     while(pNode != pHead);
     printf("\n");
}


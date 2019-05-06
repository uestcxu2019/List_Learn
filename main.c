#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: 刘旭芝
 * Date: 2019.05.06
 * 初步接触单向循环链表
*/


//定义一个节点
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;


int main()
{
    //建立三个节点
    Node Stu1,Stu2,Stu3;

    //建立一个简单的单向循环链表
    Stu1.next = &Stu2;
    Stu2.next = &Stu3;
    Stu3.next = &Stu1;

    //给链表成员赋值
    strcpy(Stu1.name,"学生1");
    strcpy(Stu2.name,"学生2");
    strcpy(Stu3.name,"学生3");

    //打印链表,不能通过判定最后一个next指向为NULL来判定
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
             printf("这是一条空链表\n");
         }
     }
     while(pNode != pHead);
     printf("\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*************************************************************
 * Author: 刘旭芝
 * Date: 2019.05.26
 * 初步接触双向链表，构建一条最简单的双向链表，并且正反打印信息
*************************************************************/


//定义一个节点
typedef struct Node1
{
    char name[30];
    struct Node1 *prev;
    struct Node1 *next;
}Node;

int main()
{
    //创建三个节点
    Node stu1,stu2,stu3;

    //节点赋值
    strcpy(stu1.name,"学生A");
    strcpy(stu2.name,"学生B");
    strcpy(stu3.name,"学生C");

    //串联成一个简单的双向链表
    stu1.prev = NULL;
    stu1.next = &stu2;

    stu2.prev = &stu1;
    stu2.next = &stu3;

    stu3.prev = &stu2;
    stu3.next = NULL;


    //正向打印链表
    Node *phead = &stu1;
    while(phead)
    {
        printf("%s  ",phead ->name);
        phead = phead ->next;
    }
    printf("\n");

    //反向打印链表
    Node *pTail = &stu3;
    while(pTail)
    {
       printf("%s  ",pTail ->name);
       pTail = pTail ->prev;
    }

    return 0;
}


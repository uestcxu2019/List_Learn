#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: 刘旭芝
 * Date: 2019.05.06
 * 向单向循环链表尾部插入新的节点
 *
 *  步骤；
 *      1.用户每输入一次，动态产生一个节点
 *      2.给节点域数据赋值然后将头部指针指向新节点，将尾部指针的next指向新节点
 *      3.将新节点的next指向原来的头部节点,
**/

//定义一个节点结构体
typedef struct Node1
{
    char name[30];
    struct Node1 *next;
}Node;


int main(void)
{
    Node *pHead = NULL; //定义一个初始化为空的头节点，用于遍历
    Node *pTail = NULL; //定义一个初始化为空的尾节点，用于插入新节点
    char name[30];

    while(1)
    {
        printf("请输入学生姓名: q(退出系统),p(打印)\n");
        scanf("%s",name);

        //退出系统
        if(strcmp(name,"q") == 0)
        {
            printf("已退出系统\n");
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
            if(pHead == NULL)//判定为空链表
            {
                pHead = pTail = pNode;
                pNode ->next =pHead;    //形成一个回环
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


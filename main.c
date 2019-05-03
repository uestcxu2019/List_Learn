#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//向链表的中部插入节点
struct Node1
{
    char name[30];
    struct Node1 *next;
};

typedef struct Node1 Node;

void PrintList(Node *pHead);

int main()
{
    //定义一条链表，两个节点A和B
    Node A;
    strcpy(A.name,"学生A");
    Node B;
    strcpy(B.name,"学生B");

    A.next = &B;
    B.next = NULL;

    PrintList(&A);

    //在A和B之间插入一个新节点
    Node C;
    strcpy(C.name,"学生C");

    //知道要插入节点的前后地址情况下
//    A.next = &C;
//    C.next = &B;
//    PrintList(&A);

    //只知道插入节点的前一个节点
//    C.next = (&A)->next;
    C.next = A.next;
     A.next = &C;
     PrintList(&A);
}

void PrintList(Node *pHead)
{
    while(pHead != NULL)
    {
        printf("%s    ",pHead->name);
        pHead = pHead->next;
    }
    printf("\n");
}

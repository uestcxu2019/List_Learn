#ifndef __LIST_H
#define __LIST_H

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


Node *CreateList(int N);
void PrintList(Node *pHead);
Node *DeleteList(Node *phead);



#endif // __LIST_H

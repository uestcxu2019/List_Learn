#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������в�����ڵ�
struct Node1
{
    char name[30];
    struct Node1 *next;
};

typedef struct Node1 Node;

void PrintList(Node *pHead);

int main()
{
    //����һ�����������ڵ�A��B
    Node A;
    strcpy(A.name,"ѧ��A");
    Node B;
    strcpy(B.name,"ѧ��B");

    A.next = &B;
    B.next = NULL;

    PrintList(&A);

    //��A��B֮�����һ���½ڵ�
    Node C;
    strcpy(C.name,"ѧ��C");

    //֪��Ҫ����ڵ��ǰ���ַ�����
//    A.next = &C;
//    C.next = &B;
//    PrintList(&A);

    //ֻ֪������ڵ��ǰһ���ڵ�
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

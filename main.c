#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ͷ����ʽ����ڵ�

struct Node1
{
    char name[30];
    struct Node1 *next;
};

typedef struct Node1 Node;


int main()
{
    Node *pHead = NULL;
    while(1)
    {
        printf("������ѧ��,q(�˳�ϵͳ),p(��ӡ)\n");
        char name[30];
        scanf("%s",name);

        //�˳�ϵͳ
        if(strcmp(name,"q")==0)
        {
           printf("�˳�ϵͳ\n");
           break;
        }

        //��ӡ��Ϣ
        if(strcmp(name,"p")==0)
        {
           Node *pNode = pHead;
           while(pNode !=NULL)
           {
               printf("%s     ",pNode->name);
               pNode = pNode->next;
           }
           printf("\n");
        }

        else
        {
            Node *pNode = (Node *)malloc(sizeof(Node));
            pNode ->next = pHead;   //���½ڵ����һ��ָ�� ֮ǰ�����ͷ�ڵ�
            strcpy(pNode->name,name);
            pHead = pNode;
        }
    }


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����β������ڵ�
/*
 *          ͷ�ڵ�(pHead)      β�ڵ�(pTail)     ����Ľڵ�(pNode)
 *          **************      **************     **************
 *          *��һ�ڵ��ַ*      *��һ�ڵ��ַ*     *��һ�ڵ��ַ*
 *          **************      **************     **************
*/




struct Node1
{
    char name[30];
    struct Node1 *next; //�����һ�ڵ��ַ
};

typedef struct Node1 Node;

int main()
{
    //һ��ָ��ͷ�ڵ㣬���ڱ�����һ��ָ��β�������ڲ����½ڵ�
    Node *pHead = NULL;
    Node *pTail = NULL;

    while(1)
    {
        printf("������ѧ��������q(�˳�),p(��ӡ)��\n");
        char name[30];
        scanf("%s",name);

        if(strcmp(name,"q")== 0)  //�˳�ϵͳ
        {
            printf("�˳�ϵͳ\n");
            break;
        }
        if(strcmp(name,"p")==0) //��ӡ
        {
            Node *pNode = pHead;
            while(pNode !=NULL)//��������
            {
                printf("%s   ",pNode->name);
                pNode = pNode->next;
            }
            printf("\n");
        }
        else    //���ѧ��
        {
            Node *pNode =(Node *)malloc(sizeof(Node));
            strcpy(pNode->name,name);
            pNode->next = NULL; //Ĭ�Ͻ�����Ϊβ���ڵ�

            //�ѽڵ����������
            /*  �ж��Ƿ�Ϊͷ�ڵ�,��Ϊǰ�潨���������ǿ�����
                ��һ�β���Ľڵ����ͷ�ڵ�Ҳ��β�ڵ�

            */
            if(pHead == NULL)
            {
                pHead = pNode;
                pTail = pNode;
            }
            else
            {
                /*  ���ڲ��õ���β���ڵ���뷨������Ҫ�滻����ʼ�������β���ڵ�
                    �ò���Ľڵ�pNode��Ϊβ���ڵ�
                */
                pTail ->next = pNode;   //��β���ڵ����һ��ָ���ַָ�����Ľڵ�
                pTail = pNode;      //�ò���Ľڵ���Ϊ��ǰβ���ڵ�
            }

        }
    }

}

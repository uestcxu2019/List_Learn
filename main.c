#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ���ڵ�
struct Node1
{
    char name[30];  //��ŵ�ǰ�ڵ������
    struct Node1 *next; //���ڴ����һ���ڵ�ĵ�ַ
};

typedef struct Node1 Node;

int main()
{
   //���������ڵ�
   Node stu1;
   Node stu2;
   Node stu3;

   //�ڵ����ݸ�ֵ
   strcpy(stu1.name,"ѧ��A");
   strcpy(stu2.name,"ѧ��B");
   strcpy(stu3.name,"ѧ��C");

   //stu1��Ϊͷ�ڵ㣬stu3��Ϊβ�ڵ�
   stu1.next = &stu2;
   stu2.next = &stu3;
   stu3.next = NULL;

   //���ϲ����ѹ������һ���򵥵ĵ�������
   Node *pNode = &stu1;
   while(pNode != NULL)
   {
       printf("������:%s\n",pNode->name);
       pNode = pNode ->next;
   }
   printf("\n");

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个节点
struct Node1
{
    char name[30];  //存放当前节点的姓名
    struct Node1 *next; //用于存放下一个节点的地址
};

typedef struct Node1 Node;

int main()
{
   //定义三个节点
   Node stu1;
   Node stu2;
   Node stu3;

   //节点数据赋值
   strcpy(stu1.name,"学生A");
   strcpy(stu2.name,"学生B");
   strcpy(stu3.name,"学生C");

   //stu1作为头节点，stu3作为尾节点
   stu1.next = &stu2;
   stu2.next = &stu3;
   stu3.next = NULL;

   //以上步骤已构建完成一个简单的单向链表
   Node *pNode = &stu1;
   while(pNode != NULL)
   {
       printf("姓名是:%s\n",pNode->name);
       pNode = pNode ->next;
   }
   printf("\n");

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//链表尾部插入节点
/*
 *          头节点(pHead)      尾节点(pTail)     插入的节点(pNode)
 *          **************      **************     **************
 *          *下一节点地址*      *下一节点地址*     *下一节点地址*
 *          **************      **************     **************
*/




struct Node1
{
    char name[30];
    struct Node1 *next; //存放下一节点地址
};

typedef struct Node1 Node;

int main()
{
    //一个指向头节点，用于遍历，一个指向尾部，用于插入新节点
    Node *pHead = NULL;
    Node *pTail = NULL;

    while(1)
    {
        printf("请输入学生姓名，q(退出),p(打印)：\n");
        char name[30];
        scanf("%s",name);

        if(strcmp(name,"q")== 0)  //退出系统
        {
            printf("退出系统\n");
            break;
        }
        if(strcmp(name,"p")==0) //打印
        {
            Node *pNode = pHead;
            while(pNode !=NULL)//遍历链表
            {
                printf("%s   ",pNode->name);
                pNode = pNode->next;
            }
            printf("\n");
        }
        else    //添加学生
        {
            Node *pNode =(Node *)malloc(sizeof(Node));
            strcpy(pNode->name,name);
            pNode->next = NULL; //默认将其作为尾部节点

            //把节点放入链表中
            /*  判定是否为头节点,因为前面建立的链表是空链表
                第一次插入的节点就是头节点也是尾节点

            */
            if(pHead == NULL)
            {
                pHead = pNode;
                pTail = pNode;
            }
            else
            {
                /*  由于采用的是尾部节点插入法，即需要替换掉初始化定义的尾部节点
                    让插入的节点pNode作为尾部节点
                */
                pTail ->next = pNode;   //让尾部节点的下一个指向地址指向插入的节点
                pTail = pNode;      //让插入的节点作为当前尾部节点
            }

        }
    }

}

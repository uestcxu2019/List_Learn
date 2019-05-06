#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: ΑυΠρΦ¥
 * Date: 2019.05.04
 * 删除链表中部节点
*/



int main()
{
    Node *p;
    p = CreateList(1);
    PrintList(p);

    p = DeleteList(p,"学生1");

    PrintList(p);

    p = DeleteList(p,"学生1");

    PrintList(p);
}

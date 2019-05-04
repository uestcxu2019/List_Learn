#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: 刘旭芝
 * Date: 2019.05.04
 * 删除链表尾部节点
*/



int main()
{
    Node *p;
    p = CreateList(5);
    PrintList(p);
    p =DeleteList(p);
}

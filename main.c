#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * Author: ����֥
 * Date: 2019.05.04
 * ɾ������β���ڵ�
*/



int main()
{
    Node *p;
    p = CreateList(5);
    PrintList(p);
    p =DeleteList(p);
}

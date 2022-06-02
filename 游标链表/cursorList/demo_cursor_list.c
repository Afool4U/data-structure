#include "cursor_list.h"

#include <stdio.h>

void printSlots(int start, int end)  // end is EXCLUDED
{
    for (int i = start; i < end; ++i)
        printf("SLOTS[%d]: %d %d\n", i, SLOTS[i].data, SLOTS[i].next);
}

int main()
{
    int l1 = clCreate();
    int l2 = clCreate();
    int l3 = clCreate();
    printf("%d %d\n", clLength(l3), clIsEmpty(l3));  // 0 1
    printSlots(0, 7);
    printf("==========\n");
    clAppend(l1, 10);
    clAppend(l2, 20);
    clAppend(l3, 30);
    clAppend(l1, 40);
    printf("%d %d\n", clLength(l1), clIsEmpty(l1));  // 1 0
    printf("%d\n", clFind(l1, 30));  // 0
    printf("%d\n", clFind(l1, 40));  // 7
    printSlots(0, 10);
    printf("**********\n");
    printf("%d\n", clInsert(clFind(l1, 10), 50));  // 1
    clInsert(clFind(l1, 10), 60);
    clPrint(l1);  // 10 60 50 40
    printf("$$$$$$$$$$\n");
    clDelete(l1, 50);
    clPrint(l1);  // 10 60 40
    printf("%d\n", clLength(l1));  // 3
    printf("@@@@@@@@@@\n");
    int l4 = clCopy(l1);
    clPrint(l4);
    printf("&&&&&&&&&&\n");
    printSlots(0, 30);
    printf("##########\n");
    printf("Free list:\n");
    clPrint(0);
    printf("\nIn the case of the above, the contents of SLOTS must match mine exactly."
           "\nBelow this point, that stops being true, due to clDestroy() and clReverse()."
           "\nIn both of these functions, there is more variety in how to approach them.\n\n");
    clDestroy(l1);
    printSlots(0, 15);
    printf("~~~~~~~~~~\n");
    printf("Free list: (data doesn't matter)\n");
    clPrint(0);
    printf("!!!!!!!!!!\n");
    clAppend(l4, 70);
    clInsert(l4, 80);  // insert at front
    printf("Before reverse:\n");
    clPrint(l4);  // 80 10 60 40 70
    printf("After reverse:\n");
    clReverse(l4);  // 70 40 60 10 80
    clPrint(l4);
}

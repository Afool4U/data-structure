#include "cursor_list.h"

#include <stdio.h>

void printSlots(int start, int end)  // end is EXCLUDED
{
    for (int i = start; i < end; ++i)
        printf("SLOTS[%d]: %d %d\n", i, SLOTS[i].data, SLOTS[i].next);
}

int main()
{
    int x = slotAlloc();
    SLOTS[x].data = 100;
    printSlots(0, 7);
    printf("===\n");
    int y = slotAlloc();
    SLOTS[y].data = 200;
    int z = slotAlloc();
    SLOTS[z].data = 300;
    printSlots(0, 7);
    printf("===\n");
    // We have three nodes; turn them into a linked list z -> x -> y.
    // Last node has next member set to 0.
    SLOTS[z].next = x;
    SLOTS[x].next = y;
    SLOTS[y].next = 0;
    printSlots(0, 7);
    printf("===\n");
    // Deallocate the middle node (x).
    slotFree(x);
    SLOTS[z].next = y;
    printSlots(0, 30);
}

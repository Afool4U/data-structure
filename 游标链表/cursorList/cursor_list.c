#include "cursor_list.h"

#include <stdio.h>
int count=0;
/**
 * "Allocates" a slot that is not currently allocated and returns its index.
 * The very first time that this function is called, the "free list" must be
 * set up, since -- initially -- all of the slots' next members are 0.
 *
 * Does NOT perform any real dynamic memory allocation; malloc() and <stdlib.h>
 * are prohibited!
 * Selects the first available node on the "free list", i.e. SLOTS[0].next.
 *
 * Returns 0 if no more available slots.
 */
int slotAlloc(void)
{
if(29==count)
return 0;
    if (0 == SLOTS[0].next)
    {
        for (int i = 0;i < NUM_SLOTS - 1;i++)  //initialize
            SLOTS[i].next = i+1;
        SLOTS[NUM_SLOTS - 1].next = 0;
    }
    int P;
    P = SLOTS[0].next;
    SLOTS[0].next = SLOTS[P].next;
count++;
    return P;
}
/**
 * "Deallocates" the slot/node that is at @index.
 * Does NOT perform any real dynamic memory deallocation; free() and <stdlib.h>
 * are prohibited!
 * Puts the "deallocated" node at the front of the "free list".
 */
void slotFree(int index)
{
    SLOTS[index].next = SLOTS[0].next;
    SLOTS[0].next = index;
count--;
}

/**
 * Returns a new empty list containing just a header node
 * or 0 if failure (i.e. out of slots).
 */
int clCreate(void)
{
    int head = slotAlloc();
    if (0 == head)
        return 0;
    SLOTS[head].next = 0;
    return head;
}

/**
 * "Deallocates" all slots in the list that starts at @head, i.e. adds all
 * nodes in this list to the "free list".
 */
void clDestroy(int head)
{
    int p = head;
    while (p)
    {
        int temp= p;
        p = SLOTS[p].next;
        slotFree(temp);
    }
}

/**
 * Adds a new node with value @val to the end of the list that contains @node.
 * (@node need not be the index of a header node.)
 * Returns 1 if success.
 * Returns 0 (and should not attempt to append) if out of slots.
 */
int clAppend(int node, int val)
{
    int newnode = slotAlloc();
    if (0 == newnode)
        return 0;
    int p = node;
    while (SLOTS[p].next)
        p = SLOTS[p].next;
    SLOTS[p].next = newnode;
    SLOTS[newnode].next = 0;
    SLOTS[newnode].data = val;
    return 1;
}
/**
 * Adds a new node with value @val immediately after @node.
 * (@node need not be the index of a header node.)
 * Returns 1 if success.
 * Returns 0 (and should not attempt to insert) if out of slots.
 */
int clInsert(int node, int val)
{
    int newnode = slotAlloc();
    if (0 == newnode)
        return 0;
    SLOTS[newnode].next = SLOTS[node].next;
    SLOTS[node].next = newnode;
    SLOTS[newnode].data = val;
    return 1;
}

/**
 * Returns slot index of first node that contains @val in the list
 * whose header node is at index @head.
 * Returns 0 if not found.
 */
int clFind(int head, int val)
{
    int p = SLOTS[head].next;
    while (p)
    {
        if (SLOTS[p].data == val)
            return p;
        p = SLOTS[p].next;       
    }
    return 0;
}

/**
 * Prints the data member of each node (except for the header node) in the
 * list whose header node is at index @head.
 * See the examples in prog_hw5.pdf for how the output should look.
 */
void clPrint(int head)
{
    printf("SLOTS[%d]: (header)\n",head);
    int p = SLOTS[head].next;
    while (p)
    {
        printf("SLOTS[%d]: %d\n",p,SLOTS[p].data);
        p = SLOTS[p].next;
    }
}

/**
 * Deletes first occurrence of a node that contains @val in the list
 * whose header node is at index @head.
 * Returns 1 if a node was deleted; returns 0 otherwise.
 */
int clDelete(int head, int val)
{
    int p =head;
    while (SLOTS[p].next)
    {
        if (SLOTS[SLOTS[p].next].data == val)
            break;
        p = SLOTS[p].next;
    }
    if (0 == SLOTS[p].next)
        return 0;
    int temp = SLOTS[SLOTS[p].next].next;
    slotFree(SLOTS[p].next);
    SLOTS[p].next = temp;
    return 1;
}

/**
 * Returns 1 if @node is a header node.
 * Otherwise, returns 0.
 */
int clIsEmpty(int node)
{
    if (0 == SLOTS[node].next)
        return 1;
    return 0;
}

/**
 * Returns the length of the given list, not counting the header node.
 * Assumes that @head is the index of a header node.
 */
int clLength(int head)
{
    int p = SLOTS[head].next;
    int cnt = 0;
    while (p)
    {
        cnt++;
        p = SLOTS[p].next;
    }
    return cnt;
}

/**
 * Deletes all nodes in the list whose header node is at index @head
 * that have the value @val.
 * Returns the number of nodes deleted.
 */
int clDeleteAll(int head, int val)
{
    int cnt = 0;
    while (clDelete(head, val))
        cnt++;
    return cnt;
}

/**
 * Creates a copy of the list whose header node is at index @head
 * and returns the index of this copy's header node.
 * Returns 0 if failure, i.e. out of slots.
 */
int clCopy(int head)
{
    int copy = clCreate();
    if (0 == copy)
        return 0;
    int p = SLOTS[head].next;
    while(p)
    { 
        if (0 == clAppend(copy, SLOTS[p].data))
            return 0;
        p= SLOTS[p].next;
    }
    return copy;
}

/**
 * Reverses the list whose header node is at index @head.
 *
 * IMPLEMENTATION DETAILS: (not normally in a header file)
 *
 * - You are not allowed to allocate or deallocate any slots in this function.
 *
 * - Whether you choose to change the nodes' data members or their next
 *   members is your choice. (The autograder won't care.)
 *   Whatever you do, the header node must remain the header node,
 *   i.e. @head should still be the index of the list's header node.
 *   In other words, you are reversing all nodes starting at SLOTS[head].next.
 *
 * OPTIONAL CHALLENGE that is like an interview problem:
 * Implement this function with O(1) auxiliary space, i.e. with a constant
 * amount of local variables/space that doesn't scale with the size of the
 * list. Do this all while having the function run in linear (O(n)) time.
 */
void clReverse(int head)
{
        int beg = 0;
        int end = 0;
        beg = SLOTS[head].next;
        end = SLOTS[beg].next;
        while (end)
        {
            SLOTS[beg].next = SLOTS[end].next;
            SLOTS[end].next = SLOTS[head].next;
            SLOTS[head].next = end;
            end = SLOTS[beg].next;
        }
 }

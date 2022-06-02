#ifndef CURSOR_LIST_H
#define CURSOR_LIST_H

/**
 * Cursor space data structures / functions / etc.
 *
 * "Header node" refers to the node used to indicate the start of the list;
 * such a node contains no data.
 *
 * A "node" refers to an occupied/"allocated" slot.
 */

#define NUM_SLOTS 30

struct Slot
{
    int data;
    int next;  // index of next slot
};

struct Slot SLOTS[NUM_SLOTS];

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
int slotAlloc(void);

/**
 * "Deallocates" the slot/node that is at @index.
 * Does NOT perform any real dynamic memory deallocation; free() and <stdlib.h>
 * are prohibited!
 * Puts the "deallocated" node at the front of the "free list".
 */
void slotFree(int index);

/**
 * Returns a new empty list containing just a header node
 * or 0 if failure (i.e. out of slots).
 */
int clCreate(void);

/**
 * "Deallocates" all slots in the list that starts at @head, i.e. adds all
 * nodes in this list to the "free list".
 */
void clDestroy(int head);

/**
 * Adds a new node with value @val to the end of the list that contains @node.
 * (@node need not be the index of a header node.)
 * Returns 1 if success.
 * Returns 0 (and should not attempt to append) if out of slots.
 */
int clAppend(int node, int val);

/**
 * Adds a new node with value @val immediately after @node.
 * (@node need not be the index of a header node.)
 * Returns 1 if success.
 * Returns 0 (and should not attempt to insert) if out of slots.
 */
int clInsert(int node, int val);

/**
 * Returns slot index of first node that contains @val in the list
 * whose header node is at index @head.
 * Returns 0 if not found.
 */
int clFind(int head, int val);

/**
 * Prints the data member of each node (except for the header node) in the
 * list whose header node is at index @head.
 * See the examples in prog_hw5.pdf for how the output should look.
 */
void clPrint(int head);

/**
 * Deletes first occurrence of a node that contains @val in the list
 * whose header node is at index @head.
 * Returns 1 if a node was deleted; returns 0 otherwise.
 */
int clDelete(int head, int val);

/**
 * Returns 1 if @node is a header node.
 * Otherwise, returns 0.
 */
int clIsEmpty(int node);

/**
 * Returns the length of the given list, not counting the header node.
 * Assumes that @head is the index of a header node.
 */
int clLength(int head);

/**
 * Deletes all nodes in the list whose header node is at index @head
 * that have the value @val.
 * Returns the number of nodes deleted.
 */
int clDeleteAll(int head, int val);

/**
 * Creates a copy of the list whose header node is at index @head
 * and returns the index of this copy's header node.
 * Returns 0 if failure, i.e. out of slots.
 */
int clCopy(int head);

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
void clReverse(int head);

#endif  // CURSOR_LIST_H

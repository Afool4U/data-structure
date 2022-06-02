#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

typedef struct _node Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

List CreateList();
void AddToStart(List* list, int v);
void ListAppend(List* list, int v);
void RemoveByValue(List* list, int v);
int TotalValues(List* list);
void InsertAfterValue(List* list, int value);
int GetIndex(List* list, int v);
void PrintAllValues(List* list);
void DeleteAllValues(List* list);
void Reverse(List* list);
void Sort(List* list);
Node* Merge(Node* source1, Node* source2);
Node* initLink(int n);
void findAndKillK(Node* head, int k, int m);
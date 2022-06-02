#include "list.h"

struct _node {
	int value;
	struct _node* next;
};

List CreateList()
{
	List l;
	l.head = NULL;
	l.tail = NULL;

	return l;
}

void AddToStart(List* list, int v)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = v;
	p->next = NULL;

	if (list->head == NULL)
	{
		list->head = list->tail = p;
	}
	else
	{
		p->next = list->head;
		list->head = p;
	}
}

void ListAppend(List* list, int v) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = v;
	p->next = NULL;

	if (list->head == NULL) {
		list->head = list->tail = p;
	}
	else {
		list->tail->next = p;
		list->tail = p;
	}
}

int GetIndex(List* list, int v)
{
	int cnt = 0;
	for (Node* p = list->head;p != NULL;p = p->next, cnt++)
	{
		if (p->value == v)
		{
			return cnt;
		}
	}
	return -1;
}

void PrintAllValues(List* list)
{
	for (Node* p = list->head;p != NULL;p = p->next)
	{
		printf("%d ", p->value);
	}
	printf("\n");
}

void DeleteAllValues(List* list)
{
	Node* prior = list->head;
	for (Node* p = prior->next;p != NULL;p = p->next)
	{
		free(prior);
		prior = p;
	}
	list->head = list->tail = NULL;
}

void Reverse(List* list) {
	Node* beg = NULL;
	Node* end = NULL;
	Node* head = list->head;
	if (head == NULL || head->next == NULL) {
		return;
	}
	beg = head;
	end = head->next;
	while (end != NULL) {
		beg->next = end->next;
		end->next = head;
		head = end;
		end = beg->next;
		list->tail = end;
	}
	list->head = head;
}

void FrontBackSplit(Node* source, Node** front, Node** back) {
	Node* slow = NULL, * fast = NULL;
	if (source == NULL || source->next == NULL) {
		/*length<2*/
		*front = source;
		*back = NULL;
	}
	else {
		slow = source;
		fast = source->next;
	}

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	/*slow在中间位置的前面*/
	*front = source;
	*back = slow->next;
	slow->next = NULL;	//完成一分为二；
}

Node* Merge(Node* source1, Node* source2) {
	Node* temp = NULL;
	if (source1 == NULL)
		return (source2);
	else if (source2 == NULL)
		return (source1);

	if (source1->value <= source2->value) {
		temp = source1;
		temp->next = Merge(source1->next, source2);
	}
	else {
		temp = source2;
		temp->next = Merge(source1, source2->next);
	}
	return temp;
}

void mergesort(Node** L) {
	Node* P = *L;
	if (P == NULL || P->next == NULL) return;
	Node* Pa, * Pb;
	FrontBackSplit(P, &Pa, &Pb);
	mergesort(&Pa);
	mergesort(&Pb);
	*L = Merge(Pa, Pb);
}

Node* merge_sort(Node* L) {
	mergesort(&L);
	return NULL;
}

void Sort(List* list) {
	mergesort(&(list->head));
	Node* p = list->head;
	while (p->next)
		p = p->next;
	list->tail = p;
}

void RemoveByValue(List* list, int v)
{
	Node* prior = list->head;

	if (prior->value == v)
	{
		list->head = prior->next;
		free(prior);
		return;
	}

	for (Node* p = prior->next;p != NULL;prior = p, p = p->next)
	{
		if (p->value == v)
		{
			if (p == list->tail)
			{
				prior->next = NULL;
				free(p);
				list->tail = prior;
				return;
			}

			prior->next = p->next;
			free(p);
			return;
		}
	}
}

int TotalValues(List* list)
{
	int sum = 0;
	for (Node* p = list->head;p != NULL;p = p->next)
	{
		sum += p->value;
	}
	return sum;
}

void InsertAfterValue(List* list, int value)
{
	int cnt = 0;
	for (Node* p = list->head;p != NULL;p = p->next)
	{
		if (p->value == value)
		{
			printf("Please input the value :");
			int v;
			scanf("%d", &v);
			Node* q = (Node*)malloc(sizeof(Node));
			q->value = v;
			q->next = NULL;

			if (list->tail == p)
			{
				list->tail->next = p;
				list->tail = p;
			}
			else
			{
				q->next = p->next;
				p->next = q;
			}
			break;
		}
	}
}

Node* initLink(int n) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->value = 1;
	head->next = NULL;
	Node* cyclic = head;
	for (int i = 2; i <= n; i++) {
		Node* body = (Node*)malloc(sizeof(Node));
		body->value = i;
		body->next = NULL;
		cyclic->next = body;
		cyclic = cyclic->next;
	}
	cyclic->next = head;
	return head;
}

void findAndKillK(Node* head, int k, int m) {
	Node* tail = head;
	while (tail->next != head) {
		tail = tail->next;
	}
	Node* p = head;
	while (p->value != k) {
		tail = p;
		p = p->next;
	}
	while (p->next != p) {
		for (int i = 1; i < m; i++) {
			tail = p;
			p = p->next;
		}
		tail->next = p->next;
		printf("出列人的编号为:%d\n", p->value);
		free(p);
		p = tail->next;
	}
	printf("出列人的编号为:%d\n", p->value);
	free(p);
}

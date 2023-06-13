#include <stdio.h>
#include <malloc.h>





struct item
{
	int data;
	struct item* next;

};

struct queue
{
	struct item* head;
	struct item* tail;
};

void enqueue(struct queue* queue, int data)
{
	if (!queue) return;

	struct item* item1 = malloc(sizeof (*item1));
	if (!item1) return;



	item1->data = data;
	item1->next = 0;

	if (queue->head == 0)
	{
		queue->head = item1;
		queue->tail = item1;

	}
	else
	{
		queue->tail->next = item1;
		queue->tail = item1;
	}

}
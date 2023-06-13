#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>


struct item
{
	int data;
	struct item* next;
};

void list_free(struct item* list)
{
	

	if (!list) return;

	struct item* p = list;
	
	while (p != 0)
	{
		//p->data = 0;
		struct item* del = p;
		p = p->next;

		free(del);

	}  // p != list
	
}






void main()
{
	struct item* item1 = malloc(sizeof(*item1));
	struct item* item2 = malloc(sizeof(*item2));
	struct item* item3 = malloc(sizeof(*item3));
	struct item* item4 = malloc(sizeof(*item4));

	

	if (!item1 || !item2 || !item3 || !item4) return;

	item1->next = item2, item2->next = item3, item3->next = item4, item4->next = 0;
	item1->data = 1, item2->data = 2, item3->data = 3, item4->data = 4;
	
	//struct item list[5];

	list_free(item1);

}
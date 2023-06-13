#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct list* p;
    int data;
};

void*xor (void* a, void* b) {
    return (void*)((long unsigned int)a ^ (long unsigned int)b);
}

struct list* x_remove_first(struct list* list)
{
    if (list == NULL) return NULL;
    struct list* next_item = list->p;
    free(list);
    if (next_item == NULL) return NULL;
    next_item->p = xor (list, next_item->p);
    return next_item;
}

struct list* destroy_list(struct list* list) {
    for (; list != NULL; list = x_remove_first(list));

    return NULL;
}

struct list* add(struct list* list, int data)
{
    struct list* item = malloc(sizeof(struct list));
    item->data = data;

    /*if(!list->p)
      list->p = list->p ^ item;

    else
      list->p = (list->p ^ item) ^ list->p;*/

      //item -> p = NULL ^ list;
    item->p = list;
    // list->p = item ^ list->p;
    if (list != NULL) {
        list->p = xor (item, list->p);
        printf("add item %d\n", data);
        printf("item=%p data=%d p=%p\n", item, item->data, item->p);
        printf("list=%p data=%d p=%p\n", list, list->data, list->p);
    }

    puts("===========");
    return item;
}

void print_list(struct list* list) {

    printf("\nPrinting list:\n");

    struct list* prev = NULL;
    struct list* tmp = list;

    while (tmp != NULL) {
        printf("tmp=%p data=%d p=%p\n", tmp, tmp->data, tmp->p);

        struct list* tmp2 = tmp;
        //tmp = tmp->p ^ prev;
        tmp = xor (tmp->p, prev);
        prev = tmp2;
    }

    puts("");
}

//------------------------------------------------------------------------------ teacher code ^
//------------------------------------------------------------------------------ my code ->


typedef struct list list;

enum bool{ true, false };
typedef enum bool bool;

list* remove_item(list* list1, list* prev)
{
    if (!list1)  return;

    
    list* next_item = xor(list1->p, prev);
    int* next_next = xor (next_item->p, list1);
    free(list1);

    next_item->p = xor (prev, next_next);

    return next_item;

}



bool if_value_exists(list* list1, int val)
{
    for ( list* curr_item = list1, *prev = NULL, *tmp ; curr_item != NULL ; tmp = curr_item, curr_item = xor(curr_item->p, prev), prev = tmp )
    {        
        if (curr_item->data == val)
        {
            printf("The value of %d exists\n", val);
            return 1;
        }
    }

    printf("The value of %d doesn't exist\n", val);
    return 0;
    
}

list* add_last(list* list1, int val)
{
    list* last_item = list1, * prev = NULL, * tmp;
    for ( ; xor(last_item->p, prev) != NULL ; tmp = last_item, last_item = xor (last_item->p, prev), prev = tmp);

    list* new_item = malloc(sizeof(list));
    if (!new_item) return;

    new_item->data = val;
    new_item->p = xor(prev, NULL);

    last_item->p = xor (prev, new_item);

    return list1;

}

list* rem_elem(list* list1, int val)
{
    if (!if_value_exists(list1, val) && printf("^-from rem_elem check\n"))
        return list1;

    for (list* curr_item = list1, *prev = NULL, *tmp ; curr_item != NULL; tmp = curr_item, curr_item = xor (curr_item->p, prev), prev = tmp)
    {
        if (curr_item->data == val)
        {
            remove_item(curr_item, prev);
            return true;
        }
    }

}




int main() {
    //struct list list1= {NULL,5};
    //struct list* list = &list1;
    struct list* list = NULL;
    list = add(list, 5);

    list = add(list, 10);
    list = add(list, 15);
    list = add(list, 20);
    //list = add_last(list, 0);
    print_list(list);
    /*if_value_exists(list, 10);
    list = rem_elem(list, 10);
    if_value_exists(list, 10);
    /*
    list = x_remove(list);
    list = x_remove(list);
    print_list(list);
    */


    /*for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
    {
      printf("%d ", tmp->data);
    }
    puts("");*/
    return 0;
}
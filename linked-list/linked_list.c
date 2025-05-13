#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void)
{
   struct list* _list = malloc(sizeof(struct list));
   if(_list == NULL)
   {
      return NULL;
   }
   _list->first = NULL;
   _list->last = NULL;
   
   return _list;
}

size_t list_count(const struct list *list)
{
   // if list is empty return 0;
   if(list->first == NULL) return 0;
   size_t count = 0;
   for(struct list_node* countNode = list->first;countNode != NULL;countNode = countNode->next)
   {
      count++;
   }
    return count;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node* newNode = malloc(sizeof(struct list_node));
   newNode->next = list->first;
   newNode->data = item_data;
   while(1)
   {
      if(newNode->next == NULL)
      {
         break;
      }
      list->first = newNode;
   }
   list->last = newNode;
}

ll_data_t list_pop(struct list *list)
{
   // mean list is empty;
   if(list->last == NULL) return -1;
   ll_data_t data = list->last->data;
   // take prev from the item to pop
   // on the new last item set the next to null
   list->last->prev->next = NULL;
   // remove last item from list
   free(list->last);
   list->last = NULL;
   // and return its data
   return data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   if(list->first == NULL) return;
   struct list_node* curr_first = list->first;
   struct list_node* new_first = malloc(sizeof(struct list_node));
   new_first->data = item_data;
   new_first->next = curr_first;
   curr_first->prev = new_first;
   list->first = new_first;
}

ll_data_t list_shift(struct list *list)
{
    if(list->first == NULL) return -1;
   ll_data_t result = list->first->data;
   if(list->first->next != NULL)
   {
      struct list_node* new_first = list->first->next;
      new_first->prev = NULL;
      free(list->first);
      list->first = new_first;
   }else
   {
      free(list->first);
      list->first = NULL;
   }
   return result;
}

void list_delete(struct list *list, ll_data_t data)
{
   struct list_node* current_node = list->first;
   while (1)
   {
      if(current_node->data == data)
      {
         break;
      }
      current_node = current_node->next;
   }
   if(current_node != NULL)
   {
      struct list_node* prevNode = current_node->prev;
      struct list_node* nextNode = current_node->next;
      if(nextNode != NULL)
      {
         prevNode->next = nextNode;
         nextNode->prev = prevNode;
      }
      else if (current_node == list->last)
      {
         list->last = prevNode;
      }
      else if(current_node == list->first)
      {
         list->first = prevNode;
      }
      free(current_node);
   }
   
}

void list_destroy(struct list *list)
{
   // list not empty
   if(list->last == NULL)
   {
      free(list);
      return;
   }
   // free list
   while (list->last != NULL)
   {
      free(list->last);
      list_shift(list);
   }
   
   // and nullify 
}

/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "free.h"

void free(void *ptr)
{
    list *node = NULL;
    if (!ptr)
        return;
    node = (void *) (size_t) node - sizeof(list);
    node->empty = true;
//    merge(node);
}

void merge(list *node)
{
    list *first = node;
    list *last = node;

    if (node->next && node->next->empty) {
        last = node->next;
        node->size += last->size;
    }
    if (node->prev && node->prev->empty) {
        first = node->prev;
        first->size += node->size;
    }
}
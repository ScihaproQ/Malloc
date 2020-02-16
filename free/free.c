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
    node = (void *) (size_t) ptr - sizeof(list);
    node->empty = true;
    merge(node);
}

void merge(list *node)
{
    list *first = NULL;

    if (node->next && node->next->empty) {
        node->size += node->next->size;
        node->next = node->next->next;
    }
    if (node->prev && node->prev->empty) {
        first = node->prev;
        first->size += node->size;
        first->next = node->next;
    }
}
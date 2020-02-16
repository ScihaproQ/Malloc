/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "realloc.h"

void *realloc(void *ptr, size_t size)
{
    list *node = NULL;

    if (!ptr)
        return malloc(size);
    node = (void *) (size_t) ptr - sizeof(list);
    if (node->size >= size)
        return ptr;
    free(ptr);
    ptr = malloc(size);
    return ptr;
}

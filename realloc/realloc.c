/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "realloc.h"

void *realloc(void *ptr, size_t size)
{
    list *tmp = ptr - sizeof(list);
    if (tmp->size > size)
        return ptr;
    else {
        void *realloced = malloc(sizeof(size));
        return realloced;
    }
}
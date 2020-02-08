/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "free.h"

void free(void *ptr)
{
    list *t = ptr - sizeof(list);
    t->empty = 1;
    (void)ptr;
}
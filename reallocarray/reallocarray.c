/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "reallocarray.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    list *tmp = ptr - sizeof(list);
    if (tmp->size > size * nmemb)
        return ptr;
    else {
        void *realloced = malloc(size * nmemb);
        return realloced;
    }
}
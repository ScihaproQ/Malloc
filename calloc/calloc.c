/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "calloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *alloc = malloc(nmemb * size);
    return alloc;
}
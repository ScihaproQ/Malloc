/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "reallocarray.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}
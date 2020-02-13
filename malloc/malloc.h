/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#ifndef PSU_2019_MALLOC_MALLOC_H
#define PSU_2019_MALLOC_MALLOC_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct list {
    struct list *next;
    size_t size;
    int empty;
    //TODO: Padding
}list;

void *malloc(size_t);

long long to_alloc(long long received, long long next);

list *find_spot(void *base, size_t size);

void *add_spot(list *list, size_t alloc_size);

#endif //PSU_2019_MALLOC_MALLOC_H

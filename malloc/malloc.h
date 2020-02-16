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
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define ALLOC(x, size) ((x + size - 1) & ~(size - 1))

typedef struct list {
    struct list *next;
    struct list *prev;
    size_t size;
    char empty;
    char _align[24];
} list;

void *malloc(size_t);

void init_head(list **head, size_t size);

void *find_spot(list *head, size_t size);

void *add_spot(list *last, size_t size);

#endif //PSU_2019_MALLOC_MALLOC_H

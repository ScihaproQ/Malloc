/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "malloc.h"

void *malloc(size_t size)
{
    static void *base = NULL;
    size_t alloc = to_alloc(size, getpagesize());
    list *spot = NULL;

    if (!base) {
        base = sbrk(sizeof(list));
        ((list *) base)->size = alloc;
        ((list *) base)->empty = 0;
        ((list *) base)->next = NULL;
        void *tmp = sbrk(alloc);
        return tmp;
    } else {
        spot = find_spot(base, size);
        return add_spot(spot, alloc);
    }
}

list *find_spot(void *base, size_t size)
{
    list *tmp = ((list *) base);
    for (; tmp->next; tmp = tmp->next) {
        if (tmp->size >= size && tmp->empty == 1)
            return tmp;
    }
    return tmp;
}

void *add_spot(list *node, size_t alloc)
{
    void *base = NULL;

    if (node->next) {
        node->empty = 0;
        base = node + 1;
        return base;
    } else {
        base = sbrk(sizeof(list));
        ((list *) base)->size = alloc;
        ((list *) base)->empty = 0;
        ((list *) base)->next = NULL;
        void *tmp = sbrk(alloc);
        node->next = base;
        return tmp;
    }
}

long long to_alloc(long long received, long long next)
{
    if ((received - next) > 0)
        return to_alloc(received, next * 2);
    return next;
}

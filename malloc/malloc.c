/*
** EPITECH PROJECT, 2020
** 
** File description:
** TODO: Add description
*/

#include "malloc.h"

void *malloc(size_t size)
{
    static list *head = NULL;

    if (!head) {
        init_head(&head, size);
        return (void *) (size_t) head + sizeof(list);
    } else
        return find_spot(head, size);
}

void init_head(list **head, size_t size)
{
    size_t alloc = ALLOC(size + sizeof(list), 2 * getpagesize());

    (*head) = sbrk(alloc);
    if ((*head) == (void *) -1) {
        (*head) = NULL;
        return;
    }
    (*head)->next = NULL;
    (*head)->prev = NULL;
    (*head)->size = alloc - sizeof(list);
    (*head)->empty = false;
}

void *find_spot(list *head, size_t size)
{
    list *tmp = head;
    list *prev = NULL;

    while (tmp != NULL) {
        if (tmp->size >= size && tmp->empty) {
            tmp->empty = false;
            return (void *) ((size_t) tmp + sizeof(list));
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return add_spot(prev, size);
}

void *add_spot(list *last, size_t size)
{
    list *new = NULL;
    size_t alloc = ALLOC(size + sizeof(list), 2 * getpagesize());

    if (size <= 0 || !last)
        return NULL;
    new = sbrk(sizeof(list) + alloc);
    if (new == (void *) -1)
        return NULL;
    last->next = new;
    new->empty = false;
    new->next = NULL;
    new->prev = last;
    new->size = alloc - sizeof(list);
    return (void *) (size_t) new + sizeof(list);
}
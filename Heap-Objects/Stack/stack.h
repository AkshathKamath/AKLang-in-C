#ifndef STACK_H
#define STACK_H
#include <stddef.h>
#include <stdlib.h>

typedef struct Stack_AK
{
    size_t count;
    size_t capacity;
    void **data;
} stack_ak;

stack_ak *stack_new(size_t capacity);

void stack_push(stack_ak *stack, void *obj);
void *stack_pop(stack_ak *stack);

void stack_free(stack_ak *stack);
void stack_remove_nulls(stack_ak *stack);

#endif
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Garbage-Collector/Mark-and-Sweep/ms.h"

void mark(vm_t *vm)
{
    for (unsigned long i = 0; i < vm->frames->count; i++)
    {
        frame_t *frame = vm->frames->data[i];
        for (unsigned long j = 0; j < frame->references->count; j++)
        {
            obj_t *obj = frame->references->data[j];
            if (obj)
                obj->is_marked = true;
        }
    }
    printf("Marked root objects\n");
    return;
}

void trace(vm_t *vm)
{
    stack_ak *dfs_stack = stack_new(1);
    for (unsigned long i = 0; i < vm->objects->count; i++)
    {
        obj_t *obj = vm->objects->data[i];
        if (obj && obj->is_marked)
            stack_push(dfs_stack, (void *)obj);
    }

    while (dfs_stack->count > 0)
    {
        obj_t *obj = stack_pop(dfs_stack);
        dfs(dfs_stack, obj);
    }
    printf("Marked non-root but referenced objects\n");
    stack_free(dfs_stack);
    return;
}

void dfs(stack_ak *dfs_stack, obj_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
        break;
    case FLOAT:
        break;
    case STRING:
        break;
    case ARRAY:
    {
        darray *arr = obj->data.a_arr;
        for (unsigned long i = 0; i < arr->size; i++)
        {
            obj_t *obj = arr->objects[i];
            if (obj && obj->is_marked == false)
            {
                obj->is_marked = true;
                stack_push(dfs_stack, arr->objects[i]);
            }
        }
    }

    default:
        break;
    }
}

void sweep(vm_t *vm)
{
    for (unsigned long i = 0; i < vm->objects->count; i++)
    {
        obj_t *obj = vm->objects->data[i];
        if (obj == NULL)
            continue;
        if (obj->is_marked)
        {
            obj->is_marked = false;
            continue;
        }
        free_object(obj);
        vm->objects->data[i] = NULL;
        printf("Found an unmarked object and freed it\n");
    }
    stack_remove_nulls(vm->objects);
}

void gc(vm_t *vm)
{
    mark(vm);
    trace(vm);
    sweep(vm);
}
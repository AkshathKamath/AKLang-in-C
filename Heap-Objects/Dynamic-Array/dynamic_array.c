#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"

void append(obj_t *obj, obj_t *new_obj)
{
    if (obj == NULL || obj->kind != ARRAY || new_obj == NULL)
    {
        return;
    }
    darray *arr = obj->data.a_arr;
    if (arr->size == arr->capacity)
    {
        obj_t **temp = realloc(arr->objects, arr->capacity * 2 * sizeof(obj_t *));
        if (temp == NULL)
        {
            return;
        }
        arr->objects = temp;
        arr->capacity = 2 * arr->capacity;
    }
    arr->objects[arr->size++] = new_obj;
    // increment_refCount(new_obj);

    return;
}

obj_t *pop(obj_t *obj)
{
    if (obj == NULL || obj->kind != ARRAY)
        return NULL;
    darray *arr = obj->data.a_arr;
    arr->size--;
    // decrement_refCount(arr->objects[arr->size]);
    return arr->objects[arr->size];
}

obj_t *get_array_obj(obj_t *obj, unsigned long index)
{
    if (obj == NULL || obj->kind != ARRAY)
    {
        return NULL;
    }
    darray *arr = obj->data.a_arr;
    if (index >= arr->size)
    {
        return NULL;
    }
    obj_t *return_obj = arr->objects[index];
    // increment_refCount(return_obj);

    return return_obj;
}

void set_array_obj(obj_t *obj, unsigned long index, obj_t *new_obj)
{
    if (obj == NULL || obj->kind != ARRAY || new_obj == NULL)
    {
        return;
    }
    darray *arr = obj->data.a_arr;
    if (index >= arr->size)
    {
        return;
    }
    // obj_t *old_obj = arr->objects[index];
    // decrement_refCount(old_obj);
    arr->objects[index] = new_obj;
    // increment_refCount(new_obj);

    return;
}

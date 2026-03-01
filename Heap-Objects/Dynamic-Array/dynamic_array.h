#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stddef.h>
#include "Heap-Objects/Primitive-Objects/object.h"

typedef struct Object obj_t;

typedef struct DynamicArray
{
    size_t size;
    size_t capacity;
    obj_t **objects; // pointer to array of pointers pointing to darray objects
} darray;

void set_array_obj(obj_t *obj, unsigned long index, obj_t *new_obj);
obj_t *get_array_obj(obj_t *obj, unsigned long index);
void append(obj_t *obj, obj_t *new_obj);
obj_t *pop(obj_t *obj);

#endif
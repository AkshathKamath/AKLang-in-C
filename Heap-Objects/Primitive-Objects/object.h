#ifndef OBJECT_H
#define OBJECT_H
#include <stddef.h>
#include <stdbool.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"

typedef struct DynamicArray darray;

typedef enum ObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    ARRAY
} obj_kind;

typedef union ObjectData
{
    int a_int;
    float a_float;
    char *a_str;
    darray *a_arr;
} obj_data;

typedef struct Object
{
    obj_kind kind;
    obj_data data;
    int ref_ct;
    bool is_marked;
} obj_t;

#include "Virtual-Machine/vm.h"

obj_t *create_int(vm_t *vm, int value);
obj_t *create_float(vm_t *vm, float value);
obj_t *create_string(vm_t *vm, char *value);
obj_t *create_array(vm_t *vm, size_t capacity);
// obj_t *reassign_object(obj_t *old_obj, obj_t *new_obj);
void free_object(obj_t *obj);
void print(obj_t *obj);

#endif
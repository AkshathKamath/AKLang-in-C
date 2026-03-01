#ifndef VM_H
#define VM_H
#include "Heap-Objects/Stack/stack.h"

typedef struct Object obj_t;

typedef struct Frame
{
    stack_ak *references;
} frame_t;

typedef struct
{
    stack_ak *frames;
    stack_ak *objects;
} vm_t;

vm_t *initialize_vm();
frame_t *create_frame();
void push_object(vm_t *vm, obj_t *obj);
void push_frame(vm_t *vm, frame_t *frame);
void push_root_object_to_frame(frame_t *frame, obj_t *obj);

#endif
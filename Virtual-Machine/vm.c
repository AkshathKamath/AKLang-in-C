#include "Virtual-Machine/vm.h"

vm_t *initialize_vm()
{
    vm_t *vm = malloc(sizeof(vm_t));
    if (vm == NULL)
        return NULL;
    vm->frames = stack_new(1);
    vm->objects = stack_new(1);

    return vm;
}

frame_t *create_frame()
{
    frame_t *frame = malloc(sizeof(frame_t));
    if (frame == NULL)
        return NULL;
    frame->references = stack_new(1);

    return frame;
}

void push_frame(vm_t *vm, frame_t *frame)
{
    stack_push(vm->frames, (void *)frame);
}

void push_object(vm_t *vm, obj_t *obj)
{
    stack_push(vm->objects, (void *)obj);
}

void push_root_object_to_frame(frame_t *frame, obj_t *obj)
{
    stack_push(frame->references, (void *)obj);
}
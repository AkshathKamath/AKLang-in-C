#ifndef MS_H
#define MS_H
#include "Virtual-Machine/vm.h"
#include "Heap-Objects/Stack/stack.h"
#include "Heap-Objects/Primitive-Objects/object.h"
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"

void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);
void dfs(stack_ak *dfs_stack, obj_t *obj);
void gc(vm_t *vm);

#endif
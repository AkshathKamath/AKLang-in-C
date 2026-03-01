#include <stdio.h>
#include <stdlib.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"
#include "Heap-Objects/Primitive-Objects/object.h"
// #include "Garbage-Collector/Reference-Counting/ref_counter.h"
#include "Virtual-Machine/vm.h"
#include "Garbage-Collector/Mark-and-Sweep/ms.h"

vm_t *vm;

int main()
{
    vm = initialize_vm();
    frame_t *main_func_frame = create_frame();

    obj_t *a = create_int(vm, 10); // Garbage
    a = create_int(vm, 5);         // Garbage
    a = create_int(vm, 8);
    push_root_object_to_frame(main_func_frame, a);

    print(a);

    push_frame(vm, main_func_frame);
    gc(vm);
    return 0;
}
#include "stack.h"

int main(int argc, char **argv) {
    if (argc < 2) return 0;

    int size = argc - 1;
    Stack *stack_a = init_stack(size);
    Stack *stack_b = init_stack(size);

    for (int i = 0; i < size; i++) {
        push(stack_a, atoi(argv[i + 1]));
    }

    if (!is_sorted(stack_a)) {
        sort(stack_a, stack_b);
    }

    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}

#include "stack.h"

void tiny_sort(Stack *stack) {
    if (stack->top < 2) return;

    if (stack->arr[stack->top] > stack->arr[stack->top - 1]) do_sa(stack);
    if (stack->top == 2 && stack->arr[stack->top] > stack->arr[0]) do_ra(stack);
    if (stack->arr[stack->top - 1] > stack->arr[0]) do_rra(stack);
}

int is_sorted(Stack *stack) {
    for (int i = 0; i < stack->top; i++) {
        if (stack->arr[i] > stack->arr[i + 1]) return 0;
    }
    return 1;
}

void sort(Stack *stack_a, Stack *stack_b) {
    int half = stack_a->size / 2;

    while (stack_a->top >= half) {
        do_pb(stack_a, stack_b);
    }

    tiny_sort(stack_a);

    while (!is_empty(stack_b)) {
        do_cheapest_move(stack_a, stack_b);
    }

    while (!is_sorted(stack_a)) {
        do_ra(stack_a);
    }
}

#include "stack.h"

// Operações de troca
void do_sa(Stack *stack_a) {
    if (stack_a->top < 1) return;
    int tmp = stack_a->arr[stack_a->top];
    stack_a->arr[stack_a->top] = stack_a->arr[stack_a->top - 1];
    stack_a->arr[stack_a->top - 1] = tmp;
    printf("sa\n");
}

void do_sb(Stack *stack_b) {
    if (stack_b->top < 1) return;
    int tmp = stack_b->arr[stack_b->top];
    stack_b->arr[stack_b->top] = stack_b->arr[stack_b->top - 1];
    stack_b->arr[stack_b->top - 1] = tmp;
    printf("sb\n");
}

void do_ss(Stack *stack_a, Stack *stack_b) {
    do_sa(stack_a);
    do_sb(stack_b);
    printf("ss\n");
}

// Push entre pilhas
void do_pa(Stack *stack_a, Stack *stack_b) {
    if (!is_empty(stack_b)) {
        push(stack_a, pop(stack_b));
        printf("pa\n");
    }
}

void do_pb(Stack *stack_a, Stack *stack_b) {
    if (!is_empty(stack_a)) {
        push(stack_b, pop(stack_a));
        printf("pb\n");
    }
}

// Operações de rotação
void do_ra(Stack *stack_a) {
    if (stack_a->top < 1) return;
    int tmp = stack_a->arr[stack_a->top];
    for (int i = stack_a->top; i > 0; i--) {
        stack_a->arr[i] = stack_a->arr[i - 1];
    }
    stack_a->arr[0] = tmp;
    printf("ra\n");
}

void do_rb(Stack *stack_b) {
    do_ra(stack_b);
    printf("rb\n");
}

void do_rr(Stack *stack_a, Stack *stack_b) {
    do_ra(stack_a);
    do_rb(stack_b);
}

// Operações de rotação reversa
void do_rra(Stack *stack_a) {
    if (stack_a->top < 1) return;
    int tmp = stack_a->arr[0];
    for (int i = 0; i < stack_a->top; i++) {
        stack_a->arr[i] = stack_a->arr[i + 1];
    }
    stack_a->arr[stack_a->top] = tmp;
    printf("rra\n");
}

void do_rrb(Stack *stack_b) {
    do_rra(stack_b);
    printf("rrb\n");
}

void do_rrr(Stack *stack_a, Stack *stack_b) {
    do_rra(stack_a);
    do_rrb(stack_b);
}

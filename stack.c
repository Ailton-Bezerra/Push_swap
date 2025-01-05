#include "stack.h"

// Inicialização da pilha
Stack *init_stack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    if (!stack) exit(EXIT_FAILURE);
    stack->arr = malloc(size * sizeof(int));
    if (!stack->arr) exit(EXIT_FAILURE);
    stack->size = size;
    stack->top = -1;  // Pilha vazia.
    return stack;
}

void free_stack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

// Operações básicas de pilha
int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == stack->size - 1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

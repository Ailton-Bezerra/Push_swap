#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Estrutura de Pilha
typedef struct {
    int *arr;  // O array contendo os elementos.
    int size;  // Capacidade máxima do array.
    int top;   // Índice do elemento no topo.
} Stack;

// Inicialização e finalização
Stack *init_stack(int size);
void free_stack(Stack *stack);

// Operações básicas de pilha
int is_empty(Stack *stack);
int is_full(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);

// Operações de ordenação e movimentação
void do_sa(Stack *stack_a);
void do_sb(Stack *stack_b);
void do_ss(Stack *stack_a, Stack *stack_b);
void do_pa(Stack *stack_a, Stack *stack_b);
void do_pb(Stack *stack_a, Stack *stack_b);
void do_ra(Stack *stack_a);
void do_rb(Stack *stack_b);
void do_rr(Stack *stack_a, Stack *stack_b);
void do_rra(Stack *stack_a);
void do_rrb(Stack *stack_b);
void do_rrr(Stack *stack_a, Stack *stack_b);

// Funções de custo e movimentação
void get_cost(Stack *stack_a, Stack *stack_b, int *cost_a, int *cost_b);
void do_cheapest_move(Stack *stack_a, Stack *stack_b);

// Algoritmos de ordenação
void sort(Stack *stack_a, Stack *stack_b);
void tiny_sort(Stack *stack);
int is_sorted(Stack *stack);

// Função auxiliar
int nb_abs(int nb);

#endif
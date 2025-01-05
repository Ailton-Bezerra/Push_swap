#include "stack.h"

int nb_abs(int nb) {
    return nb < 0 ? -nb : nb;
}

void get_cost(Stack *stack_a, Stack *stack_b, int *cost_a, int *cost_b) {
    for (int i = 0; i <= stack_b->top; i++) {
        cost_b[i] = i <= stack_b->top / 2 ? i : (stack_b->top - i) * -1;

        int target_pos = 0;
        int min_diff = INT_MAX;

        for (int j = 0; j <= stack_a->top; j++) {
            int diff = stack_a->arr[j] - stack_b->arr[i];
            if (diff > 0 && diff < min_diff) {
                min_diff = diff;
                target_pos = j;
            }
        }

        if (min_diff == INT_MAX) {
            for (int j = 0; j <= stack_a->top; j++) {
                if (stack_a->arr[j] < stack_a->arr[target_pos]) {
                    target_pos = j;
                }
            }
        }

        cost_a[i] = target_pos <= stack_a->top / 2 ? target_pos : (stack_a->top - target_pos) * -1;
    }
}

void do_cheapest_move(Stack *stack_a, Stack *stack_b) {
    int cost_a[stack_b->size], cost_b[stack_b->size];

    get_cost(stack_a, stack_b, cost_a, cost_b);

    int cheapest = INT_MAX, move_a = 0, move_b = 0;

    for (int i = 0; i <= stack_b->top; i++) {
        int total_cost = nb_abs(cost_a[i]) + nb_abs(cost_b[i]);
        if (total_cost < cheapest) {
            cheapest = total_cost;
            move_a = cost_a[i];
            move_b = cost_b[i];
        }
    }

    while (move_a < 0 && move_b < 0) {
        do_rrr(stack_a, stack_b);
        move_a++;
        move_b++;
    }
    while (move_a > 0 && move_b > 0) {
        do_rr(stack_a, stack_b);
        move_a--;
        move_b--;
    }

    while (move_a != 0) {
        if (move_a > 0) do_ra(stack_a), move_a--;
        else do_rra(stack_a), move_a++;
    }

    while (move_b != 0) {
        if (move_b > 0) do_rb(stack_b), move_b--;
        else do_rrb(stack_b), move_b++;
    }

    do_pa(stack_a, stack_b);
}

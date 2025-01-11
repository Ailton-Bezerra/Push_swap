/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:32:30 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:40:03 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rotate(NULL, stack_b, "rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rev_rotate(NULL, stack_b, "rrb");
			(*cost)++;
		}
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rotate(stack_a, NULL, "ra");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rev_rotate(stack_a, NULL, "rra");
			(*cost)++;
		}
	}
}

static void	do_rrotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rev_rotate(a, b, "rrr");
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rotate(a, b, "rr");
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		do_rrotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_push(stack_a, stack_b, "pa");
}

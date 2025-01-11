/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:52 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:23:26 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	highest_index(t_stack *stack_a)
{
	int	index;

	index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index > index)
			index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (index);
}

static void	push_up_to_3(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (stack_size > 6 && i < stack_size && pushed < (stack_size / 2))
	{
		if ((*stack_a)->index <= (stack_size / 2))
		{
			do_push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			do_rotate(stack_a, NULL, "ra");
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		do_push(stack_a, stack_b, "pb");
		pushed++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	stack_size;
	int	lowest_pos;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rev_rotate(stack_a, NULL, "rra");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_rotate(stack_a, NULL, "ra");
			lowest_pos--;
		}
	}
}

void	sort_three(t_stack **stack_a)
{
	int	highest;

	if (is_sorted(*stack_a))
		return ;
	highest = highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		do_rotate(stack_a, NULL, "ra");
	else if ((*stack_a)->next->index == highest)
		do_rev_rotate(stack_a, NULL, "rra");
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	push_up_to_3(stack_a, stack_b, stack_size);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

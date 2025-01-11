/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:20 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:39:10 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > (size_b / 2))
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > (size_a / 2))
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if ((ft_abs(temp->cost_a) + ft_abs(temp->cost_b)) < ft_abs(cheapest))
		{
			cheapest = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}	
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

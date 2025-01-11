/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:33:44 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:25:50 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_position(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

static int	get_target(t_stack **a, int idx_b, int idx_target, int target_pos)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if ((temp->index > idx_b) && (temp->index < idx_target))
		{
			idx_target = temp->index;
			target_pos = temp->pos;
		}
		temp = temp->next;
	}
	if (idx_target != INT_MAX)
		return (target_pos);
	temp = *a;
	while (temp)
	{
		if (temp->index < idx_target)
		{
			idx_target = temp->index;
			target_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (target_pos);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		target_pos;

	temp = *stack_b;
	target_pos = 0;
	get_position(stack_a);
	get_position(stack_b);
	while (temp)
	{
		target_pos = get_target(stack_a, temp->index, INT_MAX, target_pos);
		temp->target_pos = target_pos;
		temp = temp->next;
	}
}

int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_int;
	int		lowest_pos;

	temp = *stack;
	lowest_int = INT_MAX;
	get_position(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_int)
		{
			lowest_int = temp->index;
			lowest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

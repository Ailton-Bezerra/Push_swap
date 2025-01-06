/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:41:45 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 17:03:48 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_lowest_pos(int *stack, int stack_size)
{
	int	i;
	int	lowest_pos;
	int	lowest_index;

	i = 0;
	lowest_pos = -1;
	lowest_index = INT_MAX;
	while (i < stack_size)
	{
		if (stack[i] < lowest_index)
		{
			lowest_index = stack[i];
			lowest_pos = i;
		}
		i++;
	}
	return (lowest_pos);
}

int	ft_get_target(int *stack_a, int size_a, int idx_b)
{
	int i;
	int target_idx;
	int target_pos;

	i = 0;
	target_idx = INT_MAX;
	target_pos = -1;
	while (i < size_a)
	{
		if (stack_a[i] > idx_b && stack_a[i] < target_idx)
		{
			target_idx = stack_a[i];
			target_pos = i;
		}
		i++;
	}
	if (target_pos == -1)
		target_pos = ft_get_lowest_pos(stack_a, size_a);
	return (target_pos);
}

void	ft_get_target_pos(t_stack *s)
{
	int i;
	int target_pos;

	i = 0;
	while (i < s->size_b)
	{
		target_pos = ft_get_target(s->stack_a, s->size_a, s->stack_b[i]);
		ft_printf("Target position for %d in stack_b: %d\n", s->stack_b[i], target_pos);
		s->pos_b[i] = target_pos;
		i++;
	}
	// ft_printf("\n");
	// i = 0;
	// while(i < s->size_b)
	// 	ft_printf("%d\n", s->pos_b[i++]);
}

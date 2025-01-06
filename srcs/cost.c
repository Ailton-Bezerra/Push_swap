/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:32:37 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 16:56:29 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_cost(t_stack *s)
{
	int i;
	int target_pos;

	i = -1;
	while (++i < s->size_b)
	{
		s->cost_b[i] = i;
		if (i > s->size_b / 2)
			s->cost_b[i] = (s->cost_b[i] - i) * -1;
		target_pos = ft_get_target(s->stack_a, s->size_a, s->stack_b[i]);
		s->cost_a[i] = target_pos;
		if (i > s->size_a / 2)
			s->cost_a[i] = (s->cost_a[i] - target_pos) * -1;
	}
}

void	ft_cheapest_move(t_stack *s)
{
	int	cheapest;
	int	total_cost;
	int	cost_a;
	int	cost_b;
	int	i;

	cheapest = INT_MIN;
	cost_a = 0;
	cost_b = 0;
	i = -1;
	while (++i < s->size_b)
	{
		total_cost = ft_abs(s->cost_a[i]) + ft_abs(s->cost_b[i]);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = s->cost_a[i];
			cost_b = s->cost_b[i];
		}
	}
	ft_domove(s, cost_a, cost_b);
}
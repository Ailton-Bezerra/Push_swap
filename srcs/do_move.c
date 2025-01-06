/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:52:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 16:34:44 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void ft_r_both(t_stack *s)
{
	while (s->cost_a > 0 && s->cost_b > 0)
	{
		ft_rotate(s->stack_a, s->size_a, "up", NULL);
		ft_rotate(s->stack_b, s->size_b, "up", NULL);
		write(1, "r", 1);
		s->cost_a--;
		s->cost_b--;
	}
}

static void ft_rr_both(t_stack *s)
{
	while (s->cost_a < 0 && s->cost_b < 0)
	{
		ft_rotate(s->stack_a, s->size_a, "down", NULL);
		ft_rotate(s->stack_b, s->size_b, "down", NULL);
		write(1, "r", 1);
		s->cost_a++;
		s->cost_b++;
	}
}

static void ft_do_rotate_a(t_stack *s)
{
		while (s->cost_a)
	{
		if (s->cost_a > 0)
		{
			ft_rotate(s->stack_a, s->size_a, "up", "a");
			s->cost_a--;
		}
		else if (s->cost_a < 0)
		{
			ft_rotate(s->stack_a, s->size_a, "down", "a");
			s->cost_a++;
		}
	}	
}

static void ft_do_rotate_b(t_stack *s)
{
	while (s->cost_b)
	{
		if (s->cost_b > 0)
		{
			ft_rotate(s->stack_b, s->size_b, "up", "b");
			s->cost_b--;
		}
		else if (s->cost_b < 0)
		{
			ft_rotate(s->stack_b, s->size_b, "down", "b");
			s->cost_b++;
		}
	}
}

void ft_domove(t_stack *s, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rr_both(s);
	else if (cost_a > 0 && cost_b > 0)
		ft_r_both(s);
	ft_do_rotate_a(s);
	ft_do_rotate_b(s);
	ft_push("pa", s);
}
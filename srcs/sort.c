/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 04:02:28 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 15:41:34 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issort(t_stack *s)
{
	int	i;
	
	i = -1;
	while (++i < s->size_a - 1)
		if (s->stack_a[i] > s->stack_a[i + 1])
			return (0);
	return (1);
}

void	ft_sort_three(t_stack *s)
{
	while(!ft_issort(s))
	{
		if (s->stack_a[0] > s->stack_a[1])
			ft_swap("sa", s->stack_a, s->size_a);
		else
			ft_rotate(s->stack_a, s->size_a, "down", "a");
	}
}

void	ft_sort_ffive(t_stack *s)
{
	while (s->size_b <= 1)
	{
		if (s->stack_a[0] == 0 || s->stack_a[0] == 1)
			ft_push("pb", s);
		else
			ft_rotate(s->stack_a, s->size_a, "up", "a");
	}
	if (s->stack_b[0] == 0)
		ft_swap("sb", s->stack_b, s->size_b);
	if (s->stack_a[2] != 4)
	{
		if (s->stack_a[0] == 4)
			ft_rotate(s->stack_a, s->size_a, "up", "a");
		else
			ft_rotate(s->stack_a, s->size_a, "down", "a");
	}
	if (s->stack_a[0] > s->stack_a[1])
		ft_swap("sa", s->stack_a, s->size_a);
	ft_push("pa", s);
	ft_push("pa", s);
}

static void	ft_push_to_b(t_stack *s)
{
	int pushed;
	int i;

	pushed = 0;
	i = 0;
	while (s->size_a > 6 && i < s->size_a && pushed < s->size_a / 2)
	{
		if (s->stack_a[0] <= s->size_a / 2)
		{
			ft_push("pb", s);
			pushed++;
	
		}
		else
			ft_rotate(s->stack_a, s->size_a, "up", "a");
		i++;
	}
	while (s->size_a > 3)
	{
		ft_push("pb", s);
		pushed++;
	}
	i = 0;
	while(i < s->size_b)
		ft_printf("%d\n", s->stack_b[i++]);
	ft_printf("\n");
	i = 0;
	while(i < s->size_a)
		ft_printf("%d\n", s->stack_a[i++]);
}

static void	ft_shift_stack(t_stack *s)
{
	int lowest_pos;
	
	lowest_pos = ft_get_lowest_pos(s->stack_a, s->size_a);
	if (lowest_pos > s->size_a / 2)
	{
		while (lowest_pos < s->size_a)
		{
			ft_rotate(s->stack_a, s->size_a, "down", "a");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rotate(s->stack_a, s->size_a, "down", "a");
			lowest_pos--;
		}
	}
}

void	ft_sort(t_stack *s)
{
	ft_push_to_b(s);
	ft_sort_three(s);
	while (s->size_b)
	{
		ft_get_target_pos(s);
		ft_get_cost(s);
		ft_cheapest_move(s);
	}
	if(!ft_issort(s))
		ft_shift_stack(s);
}
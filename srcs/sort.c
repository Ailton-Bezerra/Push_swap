/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 04:02:28 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 18:24:29 by ailbezer         ###   ########.fr       */
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
	if (s->stack_a[2] != 2)
	{
		if (s->stack_a[0] == 2)
			ft_rotate(s->stack_a, s->size_a, "up", "a");
		else
			ft_rotate(s->stack_a, s->size_a, "down", "a");
	}
	if (s->stack_a[0] > s->stack_a[1])
		ft_swap("sa", s->stack_a, s->size_a);
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

void ft_radix(t_stack *s)
{
	int i;
	int size;
	int	bsize;

	i = -1;
	while (++i < s->size_a)
	{
		size = s->size_a;
		while (size-- && !ft_issort(s))
		{
			if (((s->stack_a[0] >> i) & 1) == 0)
				ft_push("pb", s);
			else
				ft_rotate(s->stack_a, s->size_a, "up", "a");
		}
		bsize = s->size_b;
		while (bsize-- && (i + 1) <= s->bit_size && !ft_issort(s))
		{
			if (((s->stack_b[0] >> i) & 1) == 0)
				ft_rotate(s->stack_b, s->size_b, "up", "b");
			else
				ft_push("pa", s);
		} 	
		if (ft_issort(s))
			while(s->size_b)
				ft_push("pa", s);
	}
	while(s->size_b)
		ft_push("pa", s);
}
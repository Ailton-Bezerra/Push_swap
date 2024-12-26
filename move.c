/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:49:57 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 12:27:51 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char *str, int *array, int size)
{
	int tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1]; 
	array[1] = tmp;
	ft_putendl(str, 1);
}

void	ft_push(char *str, t_stack *s)
{
	int	tmp;
	
	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->size_b <= 0)
			return ;
		tmp = s->stack_b[0];
		ft_memmove(s->stack_a + 1, s->stack_a, sizeof(int) * s->size_a);
		s->stack_a[0] == tmp;
		s->size_b--;
		ft_memmove(s->stack_b, s->stack_b + 1, sizeof(int) * s->size_b);
		s->size_a++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->size_a <= 0)
			return ;
		tmp = s->stack_a[0];
		ft_memmove(s->stack_b + 1, s->stack_b, sizeof(int) * s->size_b);
		s->stack_b[0] == tmp;
		s->size_a--;
		ft_memmove(s->stack_a, s->stack_a + 1, sizeof(int) * s->size_a);
		s->size_b++;
	}
	ft_putendl_fd(str, 1);
}

void	ft_rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}

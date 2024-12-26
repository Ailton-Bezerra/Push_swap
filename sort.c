/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 04:02:28 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/20 04:10:41 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stack *s)
{
	if (s->stack_a[2] != 2)
	{
		if (s->stack_a[0] == 2)
			rotate(s->stack_a, s->size_a, "up", "a");
		else
			rotate(s->stack_a, s->size_a, "down", "a");
	}
	if (s->stack_a[0] > s->stack_a[1])
		swap("sa", s->stack_a, s->size_a);
}

void	sort_four_to_five_elements(t_stack *s)
{
	while (s->size_b <= 1);
}
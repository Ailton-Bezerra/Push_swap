/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:10:38 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:18:44 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "pa", 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(move, "pb", 2) == 0)
		push(stack_a, stack_b);
	if (move)
		ft_putendl_fd(move, 1);
}

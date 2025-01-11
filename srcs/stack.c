/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:01:53 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:26:58 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*get_tail(t_stack *stack_a)
{
	while (stack_a && stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

t_stack	*get_before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack_a, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	tail = get_tail(*stack_a);
	tail->next = new;
}

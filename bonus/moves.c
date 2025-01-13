/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:29:27 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/13 14:24:48 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = get_tail(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tail = get_tail(*stack);
	before_tail = get_before_tail(*stack);
	before_tail->next = NULL;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
}

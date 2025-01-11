/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:35:34 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:17:56 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	tail = get_tail(*stack);
	temp->next = NULL;
	tail->next = temp;
}

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_tail(*stack);
	before_tail = get_before_tail(*stack);
	before_tail->next = NULL;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "ra", 2) == 0)
		rotate(stack_a);
	else if (ft_strncmp(move, "rb", 2) == 0)
		rotate(stack_b);
	else if (ft_strncmp(move, "rr", 2) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (move)
		ft_putendl_fd(move, 1);
}

void	do_rev_rotate(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "rra", 3) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(move, "rrr", 3) == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
	if (move)
		ft_putendl_fd(move, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:53:27 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:28:16 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = temp;
		}
		stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			temp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = temp;
		}
		stack_b = NULL;
	}
}

void	free_args(char **args, int args_c)
{
	while (args_c > 0)
		free(args[--args_c]);
	free(args);
}

void	free_and_exit(t_stack **stack_a, t_stack **stack_b, char *msg, int out)
{	
	if (stack_a || stack_b)
		free_stacks(stack_a, stack_b);
	if (msg)
		write(2, "Error\n", 6);
	if (out)
		exit(1);
}

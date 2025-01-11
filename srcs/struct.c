/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:25:44 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:33:19 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_a = -1;
	new->next = NULL;
	return (new);
}

static long	ft_atol(char *str)
{
	int		i;
	int		signal;
	long	nb;

	i = 0;
	signal = 1;
	nb = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (nb * signal);
}

t_stack	*fill_stacka(int args_c, char **args)
{
	int		i;
	long	nb;
	t_stack	*stack_a;

	i = -1;
	stack_a = NULL;
	nb = 0;
	while (++i < args_c)
	{
		nb = ft_atol(args[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_and_exit(&stack_a, NULL, "error", 1);
		if (i == 0)
			stack_a = new_node((int)nb);
		else
			stack_add_bottom(&stack_a, new_node((int)nb));
	}
	free_args(args, count_args(args));
	return (stack_a);
}

void	get_indexes(t_stack *stack, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack;
		highest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

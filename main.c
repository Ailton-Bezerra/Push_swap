/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:49:02 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/10 15:21:43 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b, stack_size);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**args;
	int		args_c;

	if (argc < 2)
		exit (1);
	args = check_and_valid_input(argc, argv);
	args_c = count_args(args);
	stack_a = fill_stacka(args_c, args);
	stack_b = NULL;
	check_duplicate(stack_a);
	stack_size = get_stack_size(stack_a);
	get_indexes(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_and_exit(&stack_a, &stack_b, NULL, 0);
	return (0);
}

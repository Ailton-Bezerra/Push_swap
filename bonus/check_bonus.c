/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:49:02 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/11 15:09:45 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	execute_moves(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		return (swap(*a));
	else if (!ft_strncmp(move, "sb\n", 3))
		return (swap(*b));
	else if (!ft_strncmp(move, "ss\n", 3))
		return (swap(*a), swap(*b));
	else if (!ft_strncmp(move, "pa\n", 3))
		return (push(b, a));
	else if (!ft_strncmp(move, "pb\n", 3))
		return (push(a, b));
	else if (!ft_strncmp(move, "ra\n", 3))
		return (rotate(a));
	else if (!ft_strncmp(move, "rb\n", 3))
		return (rotate(b));
	else if (!ft_strncmp(move, "rr\n", 3))
		return (rotate(a), rotate(b));
	else if (!ft_strncmp(move, "rra\n", 4))
		return (rev_rotate(a));
	else if (!ft_strncmp(move, "rrb\n", 4))
		return (rev_rotate(b));
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (rev_rotate(a), rev_rotate(b));
}

static int	check_moves(char *move)
{
	int	valid;

	valid = 0;
	if (!ft_strncmp(move, "sa\n", 3) || !ft_strncmp(move, "sb\n", 3))
		valid = 1;
	else if (!ft_strncmp(move, "ss\n", 3))
		valid = 1;
	else if (!ft_strncmp(move, "pa\n", 3) || !ft_strncmp(move, "pb\n", 3))
		valid = 1;
	else if (!ft_strncmp(move, "ra\n", 3) || !ft_strncmp(move, "rb\n", 3))
		valid = 1;
	else if (!ft_strncmp(move, "rr\n", 3))
		valid = 1;
	else if (!ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move, "rrb\n", 4))
		valid = 1;
	else if (!ft_strncmp(move, "rrr\n", 4))
		valid = 1;
	return (valid);
}

void	wait_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		if (check_moves(move) == 0)
			free_and_exit(stack_a, stack_b, "Error", 1);
		else
			execute_moves(stack_a, stack_b, move);
		free(move);
	}
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
	wait_moves(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_and_exit(&stack_a, &stack_b, NULL, 0);
	return (0);
}

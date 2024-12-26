/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:48:50 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 12:25:05 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stacks;
	
	ft_check_valid_input(argc, argv);
	stacks = malloc(sizeof(t_stack));
		if (!stacks)
			ft_free_all(NULL, "Error\n");
	ft_initialize_struct(stacks, argc - 1, argv);
	// ft_printf("%s, %s, %d, %d\n", stacks->stack_a, stacks->stack_b, stacks->size_a, stacks->size_a);
	ft_concat(argc, argv, stacks);
	// ft_printf("%s\n", stacks->concat);
	ft_creat_stacka(stacks);
	// int i = 0;
	// while(i < stacks->size_a)
	// 	ft_printf("%d\n", stacks->stack_a[i++]);
	ft_check_duplicate(stacks);
	ft_creat_index(stacks);
	// i = 0;
	// while(i < stacks->size_a)
	// 	ft_printf("%d\n", stacks->stack_a[i++]);
	// ft_free_all(stacks,"Error");
	if ((stacks->size_a == 2) && (stacks->stack_a[0] > stacks->stack_a[1]))
		ft_swap()
	return (0);
}
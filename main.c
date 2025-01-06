/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:48:50 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 16:27:16 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stacks;
	
	ft_check_valid_input(argc, argv);
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		ft_free_all(NULL, "Error\n");
	ft_initialize_struct(stacks, argc, argv);
	// ft_printf("%s, %s, %d, %d\n", stacks->stack_a, stacks->stack_b, stacks->size_a, stacks->size_a);
	// ft_printf("%s\n", stacks->concat);
	// int i = 0;
	// while(i < stacks->size_a)
	// 	ft_printf("%d\n", stacks->stack_a[i++]);
	// ft_printf("%d", stacks->size_a);
	ft_check_duplicate_or_sort(stacks);
	ft_creat_index(stacks);
	// i = 0;
	// while(i < stacks->size_a)
	// 	ft_printf("%d\n", stacks->stack_a[i++]);
	if ((stacks->size_a == 2) && (stacks->stack_a[0] > stacks->stack_a[1]))
		ft_swap("sa", stacks->stack_a, stacks->size_a);
	else if (stacks->size_a == 3)
		ft_sort_three(stacks);
	else if (stacks->size_a == 4 || stacks->size_a == 5)
		ft_sort_ffive(stacks);
	// int i = 0;
	// while(i < stacks->size_a)
	// 	ft_printf("%d\n", stacks->stack_a[i++]);
	else
	{
		ft_sort(stacks);
		// ft_radix(stacks);
	}
	// ft_free_all(stacks,"Error");
	return (0);
}
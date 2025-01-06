/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:43:45 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 16:19:42 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*pos_a;
	int		*pos_b;
	int		*cost_a;
	int		*cost_b;
	int		size_a;
	int		size_b;
	char	*concat;
}			t_stack;

/* =========== check_error =========== */
void	ft_free_all(t_stack *s, char *msg);
void	ft_check_valid_input(int argc, char *argv[]);
void	ft_check_duplicate_or_sort(t_stack *s);

/* ============ struct ============= */
void	ft_initialize_struct(t_stack *s, int argc, char *argv[]);

/* ============= utils ============= */
void	ft_creat_index(t_stack *s);
int		ft_count_wd(char *s, char c);

/* ============= move ============= */
void	ft_push(char *str, t_stack *s);
void	ft_swap(char *str, int *array, int size);
void	ft_rotate(int *array, int size, char *direction, char *list);

/* ============= sort ============= */
// void	ft_radix(t_stack *s);
void	ft_sort(t_stack *s);
int		ft_issort(t_stack *s);
void	ft_sort_three(t_stack *s);
void	ft_sort_ffive(t_stack *s);

/* ============= position ============= */
void	ft_get_target_pos(t_stack *s);
int		ft_get_lowest_pos(int *stack, int stack_size);
int		ft_get_target(int *stack_a, int size_a, int idx_b);

/* ============= cost ============= */
void	ft_get_cost(t_stack *s);
void	ft_cheapest_move(t_stack *s);

/* ============= do_move ============= */
void ft_domove(t_stack *s, int cost_a, int cost_b);

#endif

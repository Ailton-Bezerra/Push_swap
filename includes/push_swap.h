/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:43:45 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/13 17:49:02 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

//========== check_input ==========
int		count_args(char **args);
void	check_duplicate(t_stack *stack_a);
char	**check_and_valid_input(int argc, char *argv[]);

//========== handle_errors ==========
void	free_and_exit(t_stack **stack_a, t_stack **stack_b, char *msg, int out);
int		is_sorted(t_stack *stack);
void	free_args(char **args, int args_c);

//========== struct ==========
t_stack	*fill_stacka(int args_c, char **args);
void	get_indexes(t_stack *stack, int stack_size);

//========== stack ==========
t_stack	*get_tail(t_stack *stack_a);
int		get_stack_size(t_stack *stack);
t_stack	*get_before_tail(t_stack *stack);
void	stack_add_bottom(t_stack **stack_a, t_stack *new);

//========== sort ==========
void	sort_three(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size);

//========== swap ==========
void	do_sa(t_stack **stack_a);

//========== push ==========
void	do_push(t_stack **stack_a, t_stack **stack_b, char *move);

//========== rotates ==========
void	do_rotate(t_stack **stack_a, t_stack **stack_b, char *move);
void	do_rev_rotate(t_stack **stack_a, t_stack **stack_b, char *move);

//========== position ==========
int		get_lowest_index_pos(t_stack **stack);
void	get_target_pos(t_stack **stack_a, t_stack **stack_b);

//========== cost ==========
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//========== do_move ==========
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

#endif

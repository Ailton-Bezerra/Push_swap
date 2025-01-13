/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:43:45 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/11 15:01:37 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
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

//========== moves ==========
void	swap(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

#endif
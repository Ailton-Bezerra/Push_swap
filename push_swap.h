/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:43:45 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 12:27:12 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	*concat;
}			t_stack;

/* =========== check_error =========== */
void	ft_check_duplicate(t_stack *s);
void	ft_free_all(t_stack *s, char *msg);
void	ft_check_valid_input(int argc, char *argv[]);

/* ============ stacks ============= */
void	ft_creat_stacka(t_stack *s);
void	ft_concat(int argc, char *argv[], t_stack *s);
void	ft_initialize_struct(t_stack *s, int argc, char *argv[]);

/* ============= utils ============= */
void	ft_creat_index(t_stack *s);
int		ft_count_wd(char *s, char c);

/* ============= move ============= */
void	ft_swap(char *str, int *array, int size);
void	ft_push(char *str, t_stack *s);


#endif

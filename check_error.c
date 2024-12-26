/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:16:09 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 12:18:07 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_stack *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s)
	{
		if (s->concat)
			free(s->concat);
		if (s->stack_a)
			free(s->stack_a);
		if (s->stack_b)
			free(s->stack_b);
		free(s);
	}
	exit(1);
}

void		ft_check_valid_input(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		ft_free_all(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			ft_free_all(NULL, "");
		while (argv[i][j])
		{
			if (((!ft_isdigit(argv[i][j]) && (argv[i][j] != ' ')
			 && (argv[i][j] != '-' && argv[i][j] != '+'))
			 || (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			 || (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			 || (argv[i][j] == '+' && argv[i][j + 1] == ' ')
			 || (argv[i][j] == '+' && argv[i][j + 1] == '\0')))
			 	ft_free_all(NULL, "Error\n");
			j++;
		}
	}
}
void	ft_check_duplicate(t_stack *s)
{
	int	i;
	int j;

	i = 0;
	while(i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			if(s->stack_a[i] == s->stack_a[j])
				ft_free_all(s, "Error\n");
			j++;
		}
		i++;
	}
}
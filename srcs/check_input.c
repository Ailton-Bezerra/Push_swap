/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:29:11 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/13 15:50:50 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*cat_args(int argc, char *argv[], int i)
{
	char	*tmp;
	char	*tmp2;
	char	*concat;

	tmp2 = ft_strdup("");
	while (++i < argc && argv[i])
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}	
	}
	concat = ft_strdup(tmp);
	if (!concat)
		free_and_exit(NULL, NULL, "Error", 1);
	if (tmp)
		free(tmp);
	return (concat);
}

char	**check_and_valid_input(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (ft_strncmp(argv[i], "", 1) == 0 || ft_strncmp(argv[i], "\t", 1))
			free_and_exit(NULL, NULL, "Error", 1);
		while (argv[i][j])
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
				&& (argv[i][j] != '-' && argv[i][j] != '+'))
				|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
				|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit(NULL, NULL, "Error", 1);
			j++;
		}
	}
	concat = cat_args(argc, argv, 0);
	return (ft_split(concat, ' '));
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

void	check_duplicate(t_stack *stack_a)
{
	t_stack	*temp_i;
	t_stack	*temp_j;

	if (!stack_a)
		return ;
	temp_i = stack_a;
	while (temp_i)
	{
		temp_j = temp_i->next;
		while (temp_j)
		{
			if (temp_i->value == temp_j->value)
				free_and_exit(&stack_a, NULL, "Error", 1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
}

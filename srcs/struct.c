/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:12:41 by ailbezer          #+#    #+#             */
/*   Updated: 2025/01/06 11:49:39 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_concat(int argc, char *argv[], t_stack *s)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	
	i = 0;
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
	s->concat = ft_strdup(tmp);
	if (!s->concat)
		ft_free_all(s, "Error\n");
	if (tmp)
		free(tmp);
}

static void	ft_creat_stacka(t_stack *s)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(s->concat, ' ');
	i = 0;
	j = 0;
	while (tmp[i] && tmp[i][0] != '\0')
	{
		s->stack_a[j++] = ft_atoi(tmp[i++]);
		free(tmp[i - 1]);
	}
	free(tmp);
}

static void ft_init_pos(t_stack *s)
{
	s->pos_a = malloc(s->size_a * sizeof(s->pos_a));
	if(!s->pos_a)
		ft_free_all(s, "Error\n");
	s->pos_b = malloc(s->size_a * sizeof(s->pos_b));
	if(!s->pos_b)
		ft_free_all(s, "Error\n");
	s->cost_a = malloc(s->size_a * sizeof(s->cost_a));
	if(!s->cost_a)
		ft_free_all(s, "Error\n");
	s->cost_b = malloc(s->size_a * sizeof(s->cost_b));
	if(!s->cost_b)
		ft_free_all(s, "Error\n");
}

void	ft_initialize_struct(t_stack *s, int argc, char *argv[])
{
	int	i;
	int count;

	i = 0;
	count = argc;
	s->size_a = 0;
	s->size_a = 0;
	while (--count)
	{
		if(ft_count_wd(argv[i + 1], ' '))
			s->size_a += ft_count_wd(argv[i + 1], ' ');
		else
			s->size_a += 1;
		i++;
	}
	s->stack_a = malloc (s->size_a * sizeof * s->stack_a);
	if (!s->stack_a)
		ft_free_all(s, "Error\n");
	s->stack_b = malloc (s->size_a * sizeof * s->stack_b);
	if (!s->stack_b)
		ft_free_all(s, "Error\n");
	ft_init_pos(s);
	ft_concat(argc, argv, s);
	ft_creat_stacka(s);
}
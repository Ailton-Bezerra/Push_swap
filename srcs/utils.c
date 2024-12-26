/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:52:21 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/26 12:17:42 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_creat_index(t_stack *s)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	tmp = malloc(s->size_a * sizeof(tmp));
	if (!tmp)
		ft_free_all(s, "Error\n");
	i = -1;
	while (++i < s->size_a)
	{
		k = 0;
		j = -1;
		while (++j < s->size_a)
		{
			if (s->stack_a[i] > s->stack_a[j])
				k++;
		}
		tmp[i] = k; 
	}
	i = s->size_a;
	while (i--)
		s->stack_a[i] = tmp[i];
	free(tmp);
}
	
int	ft_count_wd(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}
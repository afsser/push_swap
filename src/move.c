/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:25 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/06/19 16:24:07 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(char *str, long *array, int size)
{
	long	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_data *nbrs)
{
	long	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (nbrs->b_size <= 0)
			return ;
		tmp = nbrs->b[0];
		ft_memmove(nbrs->a + 1, nbrs->a, sizeof(long) * nbrs->a_size);
		nbrs->a[0] = tmp;
		nbrs->b_size--;
		ft_memmove(nbrs->b, nbrs->b + 1, sizeof(long) * nbrs->b_size);
		nbrs->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (nbrs->a_size <= 0)
			return ;
		tmp = nbrs->a[0];
		ft_memmove(nbrs->b + 1, nbrs->b, sizeof(long) * nbrs->b_size);
		nbrs->b[0] = tmp;
		nbrs->a_size--;
		ft_memmove(nbrs->a, nbrs->a + 1, sizeof(long) * nbrs->a_size);
		nbrs->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(long *array, int size, char *direction, char *list)
{
	long	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(long) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(long) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}

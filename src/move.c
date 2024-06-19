#include "../include/push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_data *nbrs)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (nbrs->b_size <= 0)
			return ;
		tmp = nbrs->b[0];
		ft_memmove(nbrs->a + 1, nbrs->a, sizeof(int) * nbrs->a_size);
		nbrs->a[0] = tmp;
		nbrs->b_size--;
		ft_memmove(nbrs->b, nbrs->b + 1, sizeof(int) * nbrs->b_size);
		nbrs->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (nbrs->a_size <= 0)
			return ;
		tmp = nbrs->a[0];
		ft_memmove(nbrs->b + 1, nbrs->b, sizeof(int) * nbrs->b_size);
		nbrs->b[0] = tmp;
		nbrs->a_size--;
		ft_memmove(nbrs->a, nbrs->a + 1, sizeof(int) * nbrs->a_size);
		nbrs->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}

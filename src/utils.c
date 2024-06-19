#include "../include/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_data *nbrs, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < nbrs->a_size)
		{
			j = i + 1;
			while (j < nbrs->a_size)
			{
				if (nbrs->a[i] == nbrs->a[j])
					free_and_exit_with_message(nbrs, "Error\n", 1);
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(nbrs))
		free_and_exit_with_message(nbrs, NULL, 1);
}

void	initialize_stacks(int argc, char **argv, t_data *nbrs)
{
	int	i;

	i = 0;
	nbrs->a_size = argc - 1;
	nbrs->b_size = 0;
	nbrs->a = malloc(nbrs->a_size * sizeof * nbrs->a);
	if (nbrs->a == NULL)
		free_and_exit_with_message(nbrs, "Error\n", 1);
	nbrs->b = malloc(nbrs->a_size * sizeof * nbrs->b);
	if (nbrs->b == NULL)
		free_and_exit_with_message(nbrs, "Error\n", 1);
	while (argv[i + 1] != NULL && i < argc)
	{
		nbrs->a[i] = ft_atol(argv[i + 1], nbrs);
		i++;
	}
}

void	create_index(t_data *nbrs)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(nbrs->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(nbrs, "Error\n", 1);
	i = -1;
	while (++i < nbrs->a_size)
	{
		k = 0;
		j = -1;
		while (++j < nbrs->a_size)
			if (nbrs->a[i] > nbrs->a[j])
				k++;
		new_a[i] = k;
	}
	i = nbrs->a_size;
	while (i--)
		nbrs->a[i] = new_a[i];
	free(new_a);
}

int	ft_atol(const char *n, t_data *nbrs)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			free_and_exit_with_message(nbrs, "Error\n", 1);
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_message(nbrs, "Error\n", 1);
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}
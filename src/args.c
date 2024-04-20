#include "../include/push_swap.h"

static void next_node(t_data **nbrs, t_data **curr)
{
	(*curr)->next = malloc(sizeof(t_data));
	if ((*curr)->next == NULL)
		failure_free(*nbrs);
	(*curr)->next->prev = *curr;
	*curr = (*curr)->next;
}

void	create_stack(int argc, char **argv, t_data **nbrs)
{
	int	i;
	t_data	*curr;

	t_data	*prev;
	prev = NULL;

	*nbrs = malloc(sizeof(t_data));
	if (*nbrs == NULL)
		failure_free(*nbrs);
	curr = *nbrs;
	i = 1;
	while (i < argc)
	{
        curr->nb = ft_atoi(argv[i]);
		curr->changed = 0;
		curr->index = i;
		curr->prev = prev;
		if(i < argc - 1)
			next_node(nbrs, &curr);
		else
			curr->next = NULL;
		prev = curr;
		i++;
	}
	(*nbrs)->prev = NULL;
}

void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && i != j)
				failure();
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			failure();
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				failure();
			j++;
		}
		i++;
	}
	check_duplicates(argc, argv);
}


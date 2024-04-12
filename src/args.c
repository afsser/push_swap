#include "../include/push_swap.h"

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

void	parse_args(int argc, char **argv, t_data **nbrs)
{
	int	i;
	t_data	*curr;

	*nbrs = malloc(sizeof(t_data));
        if (*nbrs == NULL)
            failure_free(*nbrs);
	curr = *nbrs;
	i = 1;
	while (i < argc)
	{
        curr->nb = ft_atol(argv[i]);
		curr->changed = 0;
		if(i < argc - 1)
		{
        	curr->next = malloc(sizeof(t_data));
        	if (curr->next == NULL)
            failure_free(*nbrs);
			curr = curr->next;
		}
		else
			curr->next = NULL;
		i++;
	}
}

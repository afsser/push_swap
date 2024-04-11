#include "../include/push_swap.h"

void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (argv[i] == argv[j])
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
	check_duplicates(argc, argv);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				failure();
			j++;
		}
		i++;
	}
}

void	parse_args(int argc, char **argv, t_data *nbrs)
{
	int	i;
	int	j;

    t_data *current;
	// nbrs->next = NULL;
	// current = NULL;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				failure();
			j++;
		}
		
        current->nb = ft_atol(argv[i]);

        // Se a lista estiver vazia, insere o novo nó como a cabeça da lista
        if (i == 1)
		{
        current->next = malloc(sizeof(t_data));
        if (current->next == NULL)
            failure_free(current);
		current = current->next;

        }
		else
		{
            // Caso contrário, adiciona o novo nó no final da lista
            // current = new_node;
            current->next = NULL;
        }
		i++;
	}
	// return (nbrs);
}
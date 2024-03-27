#include "../include/push_swap.h"

void	failure(t_data *nbrs)
{
    t_data *temp;

    // Ponteiro temporário para percorrer a lista encadeada

    // Percorre a lista encadeada
    while (nbrs != NULL) {
        // Armazena o próximo nó antes de liberar o nó atual
        temp = nbrs->next;
        free(nbrs);
        // Atualiza nbrs para apontar para o próximo nó
        nbrs = temp;
    }
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// char **ft_atostr(int *nbrs, int argc)
// {
// 	char	**nbr_strs;
// 	int	i;

// 	nbr_strs = malloc(sizeof(char *) * argc);
// 	i = 0;
// 	while (i < argc)
// 	{
// 		nbr_strs[i] = ft_itoa(nbrs[i]);
// 		i++;
// 	}
// 	return (nbr_strs);
// }

void	check_duplicates(char **argv, int argc)
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
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

t_data	*parse_args(int argc, char **argv)
{
	int	i;
	int	j;
	t_data *head;
    t_data *current;

	head = NULL;
	current = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				failure(head);
			j++;
		}
		// Cria um novo nó para cada número inteiro encontrado
        t_data *new_node = malloc(sizeof(t_data));
        if (new_node == NULL)
            failure(head);
        new_node->nb = ft_atoi(argv[i]);
        new_node->next = NULL;
        // Se a lista estiver vazia, insere o novo nó como a cabeça da lista
        if (head == NULL)
		{
            head = new_node;
            current = new_node;
        }
		else
		{
            // Caso contrário, adiciona o novo nó no final da lista
            current->next = new_node;
            current = new_node;
        }
		i++;
	}
	return (head);
}

// int	*parse_args(int argc, char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	*nbrs;

// 	i = 1;
// 	nbrs = malloc(sizeof(int) * argc - 1);
// 	while (i < argc)
// 	{
// 		j = 0;
// 		if (argv[i][j] == '-')
// 			j++;
// 		while (argv[i][j])
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 				failure(nbrs);
// 			j++;
// 		}
// 		nbrs[i - 1] = ft_atoi(argv[i]);
// 		i++;
// 	}
// 	return (nbrs);
// }

// void	change_nbrs(int *nbrs, int argc)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < argc)
// 	{
// 		nbrs[i] = i;
// 		i++;
// 	}
// }

void	change_nbrs(t_data *copy)
{
	int	i;
	
	i = 1;
	while (copy->next)
	{
		copy->index->nb = i;
		i++;
	}
}


#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_data	*stack_a;
	// t_data	*stack_b;
	// int		*nbrs;
	t_data	*nbrs;
	t_data	*copy;

	nbrs = parse_args(argc, argv);
	check_duplicates(argv, argc);
	copy = copy_list(nbrs);
	bubble_sort(copy);
	change_nbrs(copy);
	// ================================== print nbrs
    while (nbrs != NULL) {
        printf("%d ", nbrs->nb);
        nbrs = nbrs->next;
    }
    printf("\n");
	// ================================== 

	// frees

	return (EXIT_SUCCESS);
}
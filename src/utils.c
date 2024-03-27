#include "../include/push_swap.h"

static void	swap(t_data *a, t_data *b)
{
    int temp = a->nb;
    a->nb = b->nb;
    b->nb = temp;
}

t_data	*bubble_sort(t_data *nbrs)
{
	int 	swapped;
	t_data	*head;

	head = nbrs;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (nbrs->next)
		{
			if (nbrs->nb > nbrs->next->nb)
			{
				swap(nbrs, nbrs->next);
				swapped = 1;
			}
			nbrs = nbrs->next;
		}
	}
	return (head);
}
t_data *copy_list(t_data *head)
{
    t_data *new_head = NULL;
    t_data *current = head;
    t_data *new_current = NULL;

    while (current != NULL) {
        t_data *new_node = (t_data *)malloc(sizeof(t_data));
        if (new_node == NULL) {
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
        }
        new_node->nb = current->nb;
        new_node->next = NULL;
        new_node->index = current; // Salva o endereço de memória do nó original no campo 'index' do nó cópia

        if (new_head == NULL) {
            new_head = new_node;
            new_current = new_node;
        } else {
            new_current->next = new_node;
            new_current = new_node;
        }
        current = current->next;
    }

    return new_head;
}
// void	bubble_sort(int arr[], int size)
// {
// 	int i;
// 	int	j;
// 	int temp;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 			j++;

// 		}
// 		i++;
// 	}
// }

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
	t_data	*temp;

	head = nbrs;
	temp = head;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (temp->next)
		{
			if (temp->nb > temp->next->nb)
			{
				swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		temp = head;
	}
	return (head);
}
static long	find_min(t_data *nbrs)
{
	long 	min;
	t_data *curr;

	min = LONG_MAX;
	curr = nbrs;
	while (curr)
	{
		if (curr->nb < min && curr->changed == 0)
			min = curr->nb;
		curr = curr->next;
	}
	return min;
}

static long change_nbr(t_data *nbrs, int sq_nbr, long min)
{
    t_data *curr;

	curr = nbrs;
    while (curr)
	{
        if (curr->nb == min)
		{
            curr->nb = sq_nbr;
			curr->changed = 1;
		}
        curr = curr->next;
    }
    return min;
}
void replace_with_sequence(t_data *nbrs, int argc)
{
	int 	sq_nbr;
	long	min;
	int		i;

	i = 0;
	sq_nbr = 1;
    // Atribui números sequenciais mantendo a ordem original da lista
    while (i < argc - 1)
	{
		min = find_min(nbrs); // Encontra o menor número na lista
		change_nbr(nbrs, sq_nbr++, min); // Encontra o menor número na lista
		i++;
    }
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

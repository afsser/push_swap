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
// t_data *copy_list(int argc, char **argv)
// {
//     t_data *new_head;
//     t_data *current = head;
//     t_data *new_current = NULL;
//     t_data *new_node;

//     while (current != NULL) {
//         new_node = (t_data *)malloc(sizeof(t_data));
//         if (new_node == NULL)
//             failure();
//         new_node->nb = current->nb;
//         new_node->next = NULL;
//         new_node->index = current; // Salva o endereço de memória do nó original no campo 'index' do nó cópia

//         if (new_head == NULL) {
//             new_head = new_node;
//             new_current = new_node;
//         } else {
//             new_current->next = new_node;
//             new_current = new_node;
//         }
//         current = current->next;
//     }

//     return new_head;
// }
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

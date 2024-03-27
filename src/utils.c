#include "../include/push_swap.h"

void	bubble_sort(int arr[], int size)
{
	int i;
	int	j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;

		}
		i++;
	}
}

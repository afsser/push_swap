#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data	t_data;
struct s_data
{
	int	nb;

};

void bubble_sort(int arr[], int size);

#endif
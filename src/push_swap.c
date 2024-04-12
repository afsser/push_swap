#include "../include/push_swap.h"

void	push_swap(t_data **stack_a, t_data **stack_b)
{
	t_data	*temp;
	int		len;
	int		i;

	len = stack_len(*stack_a);
	i = 0;
	while (i < len)
	{
		temp = get_min(*stack_a);
		while (temp->nb != find_min(*stack_a))
		{
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		if (temp->nb == find_min(*stack_a))
			pb(stack_a, stack_b, 0);
		i++;
	}
	while (*stack_b)
		pa(stack_b, stack_a, 0);
}
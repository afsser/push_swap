#include "../include/push_swap.h"

void failure(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_struct(t_data *nbrs)
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
}



void	failure_free(t_data *nbrs)
{
	free_struct(nbrs);
	failure();
}

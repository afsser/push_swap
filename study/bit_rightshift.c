#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int nb;
	int shift;

	if (argc != 3)
	{
		printf("Error\n");
		return 1;
	}
	nb = atoi(argv[1]);
	shift = atoi(argv[2]);
	printf("%d >> %d\n", nb, nb>>shift);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(long int nbr, char *base)
{
	int				size;
	int				print_len;
	long long int	lli;

	lli = nbr;
	print_len = 0;
	size = ft_strlen(base);
	if (lli < 0)
	{
		lli = -lli;
		ft_printchar('-');
	}
	if (lli >= size)
		ft_putnbr_base(lli / size, base);
	ft_printchar(base[lli % size]);
	// return (print_len);
}

int main(int argc, char **argv)
{
	int nb;
	int nb2;

	if (argc != 3)
	{
		printf("Error\n");
		return 1;
	}
	nb = atoi(argv[1]);
	nb2 = atoi(argv[2]);

	// ft_putnbr_base(nb, "01");
	// write(1, " ", 1);

	ft_putnbr_base(nb, "01");
	write(1, "\n", 1);
	ft_putnbr_base(nb2, "01");
	write(1, "\n", 1);
	printf("%d&%d == ", nb, nb2);
	printf("%d\n", nb&nb2);
	write(1, "\n", 1);
	return 0;
}

//add_prime_sum

#include <unistd.h>

void	ft_putnbr(int nbr){
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	wprime(int nbr){
	int	res = 0;

	for (; nbr > 0; nbr--)
		if (nbr % 2 == 1)
			res += nbr;

	return res == 0 ? res : res + 1;
}

int	ft_atoi(char *str){
	int	nbr = 0;

	if (str[0] != '0')
		while (*str){
			nbr = nbr * 10 + (*str - '0');
			str += 1;
		}
	return nbr;
}


int	main(int ac, char **av){
	ac == 2 ? ft_putnbr(wprime(ft_atoi(av[1]))) : ft_putnbr(0);
	write(1, "\n", 1);
	return 0;
}
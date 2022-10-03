//print_hex

#include <unistd.h>

int	ft_atoi(char *str){
	int	num = 0;

	for (; *str; str += 1)
		num = num * 10 + (*str - '0');
	return num;
}

void	ft_putnbr(int nbr){
	if (nbr > 16)
		ft_putnbr(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

int	main(int ac, char **av){
	if (ac == 2){
		ft_putnbr(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return 0;
}
//tab_mult

#include <unistd.h>

void	ft_putnbr(int nbr){
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	ft_atoi(char *str){
	int	num = 0;

	for(; *str; str += 1)
		num = num * 10 + (*str - '0');
	return num;
}

int	main(int ac, char **av){
	if (ac == 2){
		for (int i = 1; i <= 9; i += 1){
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(av[1]));
			write(1, " = ", 3);
			ft_putnbr(ft_atoi(av[1]) * i);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
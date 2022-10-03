//fizzbuzz

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr > 9){
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		write(1, &"0123456789"[nbr % 10], 1);
}

int	main(void){

	for (int i = 1; i <= 100; i++){
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
	}
}
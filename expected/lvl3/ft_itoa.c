//ft_itoa

#include <stdlib.h>

char	ft_putnbr(int nbr){
	return "0123456789"[nbr % 10];
}

char	*ft_itoa(int nbr){
	char	flag = 0, *str = malloc(sizeof(str) * 12);

	str[11] = 0;
	if (nbr < 0 && ++flag)
		nbr = -nbr;
	if (nbr != 0 && nbr != -2147483648){
		for (; nbr; nbr /= 10)
			*--str = ft_putnbr(nbr);
		if (flag == 1)
			*--str = '-';
	}
	return nbr == 0 ? "0" : nbr == -2147483648 ? "-2147483648" : str;
}
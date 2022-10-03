//rev_wstr

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str, char tofind){
	int	i = 0;
	for (; str[i]; i += 1)
		if (str[i] == tofind) break;
	return i;
}

void	ft_strrev(char *str, char tofind){
	int	temp, len = ft_strlen(str, tofind) - 1;

	for (int i = 0; i < len; i += 1){
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		len -= 1;
	}
}

int	main(int ac, char **av){
	if (ac == 2){
		ft_strrev(av[1], 0);
		for (int i = 0; av[1][i]; i += 1){
			if (av[1][i - 1] <= ' ')
				ft_strrev(av[1] + i, ' ');
		}
		for (int i = 0; av[1][i]; i += 1)
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return 0;
}
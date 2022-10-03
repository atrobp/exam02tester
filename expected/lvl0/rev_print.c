//rev_print

#include <unistd.h>


int	ft_strlen(char *str){
	int i = 0;
	for (; str[i]; i++);
	return i;
}

int	main(int ac, char **av){
	if (ac == 2)
		for (int i = ft_strlen(av[1]) - 1; i >= 0; i--)
			write(1, &av[1][i], 1);
	write(1, "\n", 1);
	return 0;
}
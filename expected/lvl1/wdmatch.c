//wdmatch

#include <unistd.h>

void	wdmatch(char *small, char *big){
	int	i = 0;
	for (; *big; big += 1){
		if (small[i] == *big){
			i += 1;
		}
		if (!small[i]){
			for (int x = 0; small[x]; x += 1)
				write(1, &small[x], 1);
			return ;
		}
	}
}

int	main(int ac, char **av){
	ac == 3 ? wdmatch(av[1], av[2]): 0;
	write(1, "\n", 1);
	return 0;
}
//inter

#include <unistd.h>

void	inter(char *small, char *big){
	int	i = 0, tab[256] = {0};

	for (; *small; ){
		if (big[i] == *small){
			if (tab[*small] == 0){
				tab[*small] = 1;
				write(1, &*small, 1);
			}
			small += 1;
			i = 0;
		}
		if (!big[i]){
			i = 0;
			small += 1;
		}
		i += 1;
	}
}

int	main(int ac, char **av){
	ac == 3 ? inter(av[1], av[2]) : 0;
	write(1, "\n", 1);
	return 0;
}
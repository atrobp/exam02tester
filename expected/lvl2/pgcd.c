//pgcd

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av){
	int	pgcd = atoi(av[1]) < atoi(av[2]) ? atoi(av[1]) : atoi(av[2]);
	if (ac == 3){
		for (; 1; pgcd -= 1){
			if (atoi(av[1]) % pgcd == 0 && atoi(av[2]) % pgcd == 0){
				printf("%d", pgcd);
				break ;
			}
		}
	}
	printf("\n");
	return 0;
}
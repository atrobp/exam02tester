//search_and_replace

#include <unistd.h>

void	snr(char *str, char *tofind, char *toreplacew){
	if (!tofind[1] && !toreplacew[1])
		while (*str){
			if (*str == *tofind)
				*str = *toreplacew;
			write(1, &*str, 1);
			str += 1;
		}
}

int	main(int ac, char **av){
	ac == 4 ? snr(av[1], av[2], av[3]) : 0;
	write(1, "\n", 1);
	return 0;
}
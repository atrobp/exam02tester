//alpha_mirror

#include <unistd.h>

void	alpha_mirror(char *str){
	for (; *str; str++){
		if (*str >= 'a' && *str <= 'm')
			*str = 'z' - (*str - 'a');
		else if (*str >= 'A' && *str <= 'M')
			*str = 'Z' - (*str - 'A');
		else if (*str >= 'n' && *str <= 'z')
			*str = 'a' - (*str - 'z');
		else if (*str >= 'N' && *str <= 'Z')
			*str = 'A' - (*str - 'Z');
		write(1, &*str, 1);
	}
}


int	main(int ac, char **av){
	ac == 2 ? alpha_mirror(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}
//repeat_alpha

#include <unistd.h>

void	repeat_alpha(char *str){

	for (; *str; str += 1){
		if (*str >= 'a' && *str <= 'z'){
			for (int r = *str - 'a'; r >= 0; r--)
				write(1, &*str, 1);
		}
		else if (*str >= 'A' && *str <= 'Z'){
			for (int r = *str - 'A'; r >= 0; r--)
				write(1, &*str, 1);
		}
		else
			write(1, &*str, 1);
	}
}

int	main(int ac, char **av){
	ac == 2 ? repeat_alpha(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}
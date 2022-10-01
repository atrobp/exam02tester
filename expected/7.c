//repeat_alpha

#include <unistd.h>

void	repeat_alpha(char *str){
	int	r = 0;
	for (int i = 0; str[i]; i++){
		r = str[i] - 'a';
		while (r >= 0){
			write(1, &str[i], 1);
			r -= 1;
		}
	}
}

int	main(int ac, char **av){
	ac == 2 ? repeat_alpha(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}
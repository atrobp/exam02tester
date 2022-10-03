//first_word

#include <unistd.h>

void	first_word(char *str){
	while (*str == ' ' || *str == '	')
		str += 1;
	while (*str > 32){
		write(1, &*str, 1);
		str += 1;
	}
}

int	main(int ac, char **av){
	ac == 2 ? first_word(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}
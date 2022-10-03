//snake_to_camel.c

#include <unistd.h>

void	snake2camel(char *str){
	for (; *str; str += 1){
		if (*str == '_'){
			str += 1;
			*str -= 32;
		}
		write(1, &*str, 1);
	}
}

int	main(int ac, char **av){
	ac == 2 ? snake2camel(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}

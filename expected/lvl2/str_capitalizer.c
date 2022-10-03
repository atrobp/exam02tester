//str_capitalizer

#include <unistd.h>

void	rstr_cap(char *str){
	for (int i = 0; str[i]; i += 1)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	for (int i = 0; str[i]; i += 1){
		if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] <= 32)
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int	main(int ac, char **av){
	if (ac > 1){
		for (int i = 1; i < ac; i++){
			rstr_cap(av[i]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
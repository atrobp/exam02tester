//expand_str

#include <unistd.h>

void	expandstr(char *str){
	int	flag = 0;

	for (int i = 0; str[i];){
		while (str[i] > ' '){
			flag = 1;
			write(1, &str[i], 1);
			i += 1;
		}
		while (str[i] == ' ' || str[i] == '	'){
			i += 1;
			if (str[i] > ' ' && flag == 1)
				write(1, "   ", 3);
		}
	}
}

int	main(int ac, char **av){
	ac == 2 ? expandstr(av[1]): 0;
	write(1, "\n", 1);
	return 0;
}
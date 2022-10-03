//rotstring

#include <unistd.h>
#include <stdio.h>

int	restofstring(char *str){
	int	flag = 0;
	for (; *str; ){
		while (*str == ' ' || *str == '	')
			str += 1;
		if (flag == 1)
			write(1, " ", 1);
		while (*str > ' '){
			flag = 1;
			write(1, &*str, 1);
			str += 1;
		}
	}
	return flag;
}

int	main(int ac, char **av){
	int	i = 0, s = 0;

	// printf("%d", ac);
	if (ac >= 1){
		for (; av[1][i]; i += 1)
			if (av[1][i] > ' ') break ;
		s = i;
		for (; av[1][i]; i += 1)
			if (av[1][i] == ' ' || av[1][i] == '	')break ;
		if (restofstring(av[1] + i) == 1) write(1, " ", 1);
		while (av[1][s] > 32){
			write(1, &av[1][s], 1);
			s += 1;
		}

	}
	write(1, "\n", 1);
	return 0;
}
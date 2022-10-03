//hidenp

#include <unistd.h>

void	putc(char c){
	write(1, &c, 1);
}

int	hidenp(char *s1, char *s2){
	for (; *s2; s2 += 1)
		if (*s2 == *s1)
			s1 += 1;
	return *s1 == 0 ? 1 : 0;
}

int	main(int ac, char **av){
	ac == 3 ? putc(hidenp(av[1], av[2]) + '0') : 0;
	write(1, "\n", 1);
	return 0;
}
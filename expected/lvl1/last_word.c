//last_word

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str){
	int	i = 0;
	for (; str[i]; i += 1);
	return i;
}

void	last_word(char *str){
	int lpos, i = ft_strlen(str) - 1;

	while (str[i] == ' ' || str[i] == '	')
		i -= 1;
	lpos = i;
	while (str[i] > 32 && i >= 0)
		i -= 1;
	for (i += 1; i <= lpos; i += 1)
		write(1, &str[i], 1);
}

int	main(int ac, char **av){
	ac == 2 ? last_word(av[1]) : 0;
	write(1, "\n", 1);
	return 0;
}
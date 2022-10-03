//union

#include <unistd.h>

void	ft_union(char *s1, char *s2){
	int tab[256] = {0};

	for (; *s1; s1 += 1)
		if (tab[*s1] == 0){
			tab[*s1] = 1;
			write(1, &*s1, 1);
		}
	for (; *s2; s2 += 1)
		if (tab[*s2] == 0){
			tab[*s2] = 1;
			write(1, &*s2, 1);
		}
}

int	main(int ac, char **av){
	ac == 3 ? ft_union(av[1], av[2]): 0;
	write(1, "\n", 1);
	return 0;
}
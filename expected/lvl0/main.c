#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void	ft_putstr(char *str);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);

int	main(int ac, char **av){
	char	dst[100];
	int		a, b;

	if (strcmp(av[1], "ft_putstr") == 0)
		ft_putstr(av[2]);
	else if (strcmp(av[1], "ft_strcpy") == 0)
		printf("%s", ft_strcpy(dst, av[2]));
	else if (strcmp(av[1], "ft_strlen") == 0)
		printf("%d", ft_strlen(av[2]));
	else if (strcmp(av[1], "ft_swap") == 0){
		a = atoi(av[2]); b = atoi(av[3]); ft_swap(&a, &b);
		printf("%d %d", a, b);
	}
	return 0;
}
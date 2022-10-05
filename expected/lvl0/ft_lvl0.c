#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void	ft_putstr(char *str);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);

int	ft_strstr(char *bigstr, char *small){
	int i;

	for (; *bigstr; bigstr += 1){
		i = 0;
		while (small[i] == *bigstr){
			i += 1;
			bigstr += 1;
			if (!small[i]) return 1;
		}
	}
	return 0;
}


int	main(int ac, char **av){
	char	*exo[4] = {"ft_putstr", "ft_strcpy", "ft_strlen", "ft_swap"};
	char	dst[100];
	int		a, b;

	for (int i = 0; i <= 3; i += 1){
		if (ft_strstr(av[0], exo[i]) == 1){
			if (i == 0)
				ft_putstr(av[1]);
			else if (i == 1)
				printf("%s", ft_strcpy(dst, av[1]));
			else if (i == 2)
				printf("%d", ft_strlen(av[1]));
			else{
				a = atoi(av[2]); b = atoi(av[3]);
				ft_swap(&a, &b); printf("%d %d", a, b);
			}
		}
	}
	return 0;
}
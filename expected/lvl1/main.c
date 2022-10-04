//main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char	*ft_strdup(char *src);
// char	*ft_strpbrk(const char *s1, const char *s2);
// int		ft_strcmp(char *s1, char *s2);
// size_t	ft_strcspn(const char *s, const char *reject);
// char	*ft_strrev(char *str);
// int		is_power_of_2(unsigned int n);
int		max(int* tab, unsigned int len);

int	main(int ac, char **av){
	int	*tab = malloc(sizeof(tab) * 5);

	// if (strcmp(av[1], "ft_strdup") == 0)
	// 	printf("%s", ft_strdup(av[2]));

	// else if (strcmp(av[1], "ft_strbprk") == 0)
	// 	printf("%s", ft_strpbrk(av[2], av[3]));

	// else if (strcmp(av[1], "ft_strcmp") == 0)
	// 	printf("%d", ft_strcmp(av[2], av[3]));

	// else if (strcmp(av[1], "ft_strcspn") == 0)
	// 	printf("%li", ft_strcspn(av[2], av[3]));

	// else if (strcmp(av[1], "ft_strcspn") == 0)
	// 	printf("%s", ft_strrev(av[2]));

	if (strcmp(av[1], "max") == 0){
		if (strcmp(av[2], "NULL") == 0){
			free(tab); printf("%d", max(tab, 5));
		}
		else{
			for (int i = 0; i < 5; i += 1){
				tab[i] = atoi(av[--ac]);
			}
			printf("%d", max(tab, 5));
		}
	}

}
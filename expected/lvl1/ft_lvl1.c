//ft_lvl1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int		ft_atoi(const char *str);
char	*ft_strdup(char *src);
char	*ft_strpbrk(const char *s1, const char *s2);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strcspn(const char *s, const char *reject);
char	*ft_strrev(char *str);
size_t	ft_strspn(const char *s, const char *reject);
int		is_power_of_2(unsigned int n);
int		max(int* tab, unsigned int len);
void	print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
unsigned char swap_bits(unsigned char octet);

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
	char	*exo[12] = {"ft_atoi", "ft_strdup", "ft_strpbrk", "ft_strcmp", "ft_strcspn", "ft_strrev", "ft_strspn", "is_power_of_2", "max", "print_bits", "reverse_bits", "swap_bits"};
	// (*void lvl1func[])() = {ft_atoi, ft_strdup, ft_strpbrk, ft_strcmp, ft_strcspn, ft_strrev, ft_strspn, is_power_of_2, max, print_bits, reverse_bits, swap_bits};
	int		*tab;

	if (!tab)
		return 0;
	for (int i = 0; i < 12; i += 1){
		if (ft_strstr(av[0], exo[i]) == 1){
			if (i == 0) printf("%d", ft_atoi(av[1]));
			else if (i == 1) printf("%s", ft_strdup(av[1]));
			else if (i == 2) printf("%s", ft_strpbrk(av[1]), av[2]);
			else if (i == 3) printf("%d", ft_strcmp(av[1], av[2]));
			else if (i == 4) printf("%li", ft_strcspn(av[1], av[2]));
			else if (i == 5) printf("%s", ft_strrev(av[1]));
			else if (i == 6) printf("%li", ft_strspn(av[1], av[2]));
			else if (i == 7) printf("%d", is_power_of_2(atoi(av[1])));
			else if (i == 8){
				if (strcmp(av[2], "NULL") == 0){
					printf("%d", max(tab, 5));
				}
				else{
					tab = malloc(sizeof(tab) * 5);
					for (int i = 0; i < 5; i += 1){
						tab[i] = atoi(av[--ac]);
					}
					printf("%d", max(tab, 5));
				}
			}
			else if (i == 9) print_bits(av[1][0]);
			else if (i == 10) printf("%c", reverse_bits(av[1][0]));
			else if (i == 11) printf("%c", swap_bits(av[1][0]));
		}
	}
	return 0;
}
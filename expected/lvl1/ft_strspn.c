//ft_strspn

#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *reject){
	size_t	i = 0;

	for (; *s; s += 1){
		i = 0;
		while (*s == reject[i]){
			i += 1;
			s += 1;
		}
	}
	return i;
}
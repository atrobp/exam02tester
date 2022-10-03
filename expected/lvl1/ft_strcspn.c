//ft_strcspn

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject){
	size_t	flag = 0, i = 0, j = 0;

	for (; s[i]; i += 1){
		j = 0;
		for (; reject[j]; j++)
			if (s[i] == reject[j]){
				flag = 1;
				break ;
			}
		if (flag == 1) break;
	}
	return i;
}
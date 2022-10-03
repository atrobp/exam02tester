//ft_strdup

#include <stdlib.h>

int	ft_strlen(char *str){
	int i = 0;
	for (; str[i]; i += 1);
	return i;
}

char	*ft_strdup(char *src){
	char	*copy = malloc(sizeof(src) * ft_strlen(src) + 1);

	if (copy){
		for (int i = 0; src[i]; i += 1)
			copy[i] = src[i];
		copy[ft_strlen(src) + 1] = 0;
		return copy;
	}
	return 0;
}
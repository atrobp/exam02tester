//ft_split

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str){
	int	i = 0;
	for (; str[i]; i += 1);
	return i;
}

char	**ft_split(char *str){
	char	**tab = malloc(sizeof(str) * ft_strlen(str) + 1);
	int		index = 0, i = 0;

	if (tab){
		tab[index] = malloc(sizeof(str) * ft_strlen(str) + 1);
		for (; *str; str += 1){
			tab[index][i] = *str;
			if (*str <= ' '){
				tab[index][i] = 0;
				i = -1;
				tab[++index] = malloc(sizeof(str) * ft_strlen(str) + 1);
			}
			i += 1;
		}
		tab[++index] = 0;
		return tab;
	}
	return 0;
}

//keep for futur testing
// int	main(){
// 	// ft_split("hello world me like beacon");
// 	char **tab = ft_split("hello world me like beacon");
// 	for (int i = 0; tab[i]; i += 1){
// 		printf("%s", tab[i]);
// 	}
// }
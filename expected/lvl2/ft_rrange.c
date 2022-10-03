//ft_rrange

#include <stdlib.h>

int	tablen(int s, int e){
	return s < e ? e - s : s - e;
}

int     *ft_range(int start, int end){
	int	*tab = malloc(sizeof(tab) * tablen(start, end) + 1);
	int	i = 0;

	for (; start != end; i++){
	    tab[i] = end;
		end < start ? (end += 1) : (end -= 1);
	}
	tab[i] = end;
	tab[++i] = 0;
	return tab;
}


// int main() {
//     int *tab = ft_range(1, 3);
//     for (int i = 0; i <= 2; i++)
//         printf("%d", tab[i]);
//     return 0;
// }
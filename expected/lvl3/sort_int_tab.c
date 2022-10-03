//sort_int_tab

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size){
	int	temp;

	for (int i = 0; i < size - 1; ){
		if (tab[i] <= tab[i + 1])
			i += 1;
		else{
			temp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = temp;
			i = 0;
		}
	}
}

int	main(){
	int	tab[] = {0, 5, 862374723 , -42, 42};
	sort_int_tab(tab, 5);
	for (int i = 0; i <= 4; i++)
		printf("%d ", tab[i]);
}
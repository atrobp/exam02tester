//ft_swap

#include <stdio.h>

void	ft_swap(int *a, int *b){
	int	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void){
	int	a = 5, b = 1;
	ft_swap(&a, &b);
	printf("%d %d", a, b);
}
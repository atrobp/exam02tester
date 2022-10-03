//paramsum

#include <unistd.h>

void	ftwrite(char c){
	write(1, &c ,1);
}

int	main(int ac, char **av){
	int	sum = ac - 1;
	sum > 0 ? ftwrite(sum + '0'): write(1, "0", 1);
	write(1, "\n", 1);
	return 0;
}
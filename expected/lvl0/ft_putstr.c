//ft_putstr

#include <unistd.h>

// int	ft_strlen(char *str){
// 	int i = 0;
// 	for (; str[i]; i++);
// 	return i;
// }

void	ft_putstr(char *str){
	int i = 0; for (; str[i]; i++);
	write(1, str, i);
}
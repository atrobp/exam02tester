//ft_strlen

int	ft_strlen(char *str){
	int i = 0;
	for (; str[i]; i++);
	return i;
}
//ft_strcmp

int	ft_strcmp(char *s1, char *s2){
	while (*s1 && *s2 && *s1 == *s2){
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}
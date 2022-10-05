//ft_strrev

static int	ft_strlen(char *str){
	int	i = 0;
	for (; str[i]; i += 1);
	return i;
}

char	*ft_strrev(char *str){
	int	temp, len = ft_strlen(str) - 1;

	for (int i = 0; i < len; i += 1){
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		len -= 1;
	}
	return str;
}
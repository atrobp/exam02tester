//ft_strpbrk

char	*ft_strpbrk(const char *s1, const char *s2){
	int	i = 0;

	for (; *s1; s1 += 1){
		i = 0;
		for (; s2[i]; i += 1){
			if (*s1 == s2[i]) return s2 + i;
		}
	}
	return 0;
}
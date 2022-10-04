//ft_atoi

int	ft_atoi(const char *str){
	int	flag = 1, nbr = 0;

	if (*str == '-' || *str == '+'){
		if (*str == '-')
			flag = -1;
		str += 1;
	}
	if (*str != '0')
		for (; *str; str += 1){
			if (*str >= '0' && *str <= '9')
				nbr = nbr * 10 + (*str - '0');
			else
				break ;
		}
	return (nbr * flag);
}
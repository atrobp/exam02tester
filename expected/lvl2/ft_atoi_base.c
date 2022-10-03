//ft_atoi_base

int	ft_atoi_base(const char *str, int str_base){
	int		num = 0, isneg = 1;

	if (*str == '-'){
		str += 1;
		isneg = -1;
	}
	while (*str){
		if (*str >= '0' && *str <= '9')
			num = num * str_base + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
		    num = num * str_base + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
		    num = num * str_base + (*str - 'A' + 10);
		else
			break ;
		str += 1;
	}
	return num * isneg;
}
//ft_atoi_base

int	ft_atoi_base(const char *str, int str_base){
	char	base[] = "0123456789";
	int		num = 0, isneg = 1;

	if (*str == '-'){
		str += 1;
		isneg = -1;
	}
	while (*str){
		if ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f')
		|| (*str >= 'a' && *str <= 'f')){
			num = num * str_base + (*str - '0');
		}
		else
			break ;
	}
	return num * isneg;
}
//is_power_of_2

int	is_power_of_2(unsigned int n){
	int	i = 1;

	for (; i <= n; i *= 2)
		if (i == n) break ;
	return i == n ? 1 : 0;
}
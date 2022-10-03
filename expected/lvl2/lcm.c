//lcm


unsigned int    lcm(unsigned int a, unsigned int b){
	int	i;

    a == 0 ? (i = 0) : b == 0 ? (i = 0) : a < b ? ( i = a ) : ( i = b);
	if (i > 0)
		for (; ; i += 1)
			if (i % a == 0 && i % b == 0)
				break ;
	return i;
}
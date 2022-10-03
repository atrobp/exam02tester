// do_op

#include <stdio.h>
#include <stdlib.h>

int	do_op(int a, char *op, int b){
	int	res;

	if (*op == '+') res = a + b;
	else if (*op == '-') res = a - b;
	else if (*op == '*') res = a * b;
	else if (*op == '/') res = a / b;
	else res = a % b;
	return res;
}

int	main(int ac, char **av){
	ac == 4 ? printf("%d", do_op(atoi(av[1]), av[2], atoi(av[3]))) : 0;
	printf("\n"); return 0;
}
//max

#include <stdlib.h>

int	max(int* tab, unsigned int len){
	int	lemax = 0, i = 0;

	if (!tab[0])
		for (; i < len; i += 1)
			if (tab[i] > lemax)
				lemax = tab[i];
	return lemax;
}




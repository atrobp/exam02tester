
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

void	flood_fill(char **tab, t_point size, t_point begin){
	static int firscall = 0;
	static int	startingchar;

	if (firscall == 0){
		startingchar = tab[begin.x][begin.y];
		firscall = 1;
	}

	if (tab[begin.x][begin.y] != startingchar || tab[begin.x])
		return;
	else
		tab[begin.x][begin.y] = 'F';
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	// flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	// flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}
int	main(){
	t_point	size = {4, 4};
	t_point	begin = {1, 0};
	char	zone[][] = {
		"0110",
		"0100",
		"1111",
		"1001",
	};
	// char **new = make_area(zone, size);
	flood_fill(zone, size, begin);
	printf("%c", zone[1][0]);
}
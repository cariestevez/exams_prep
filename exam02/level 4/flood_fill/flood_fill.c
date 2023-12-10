#include <stdio.h>
#include <stdlib.h>

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	recur_fill(char start, char **tab, t_point size, t_point begin);
void  flood_fill(char **tab, t_point size, t_point begin);
//char** make_area(char** zone, t_point size);

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char start = tab[begin.y][begin.x];

	recur_fill(start, tab, size, begin);
}

void	recur_fill(char start, char **tab, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return;
	if (tab[begin.y][begin.x] != start)
		return;
	if (tab[begin.y][begin.x] == start)
		tab[begin.y][begin.x] = 'F';
	//derecha
	begin.x = begin.x + 1;
	recur_fill(start, tab, size, begin);
	//izquierda
	begin.x = begin.x - 2;
	recur_fill(start, tab, size, begin);
	//arriba
	begin.x = begin.x + 1;
	begin.y = begin.y - 1;
	recur_fill(start, tab, size, begin);
	//abajo
	begin.y = begin.y + 2;
	recur_fill(start, tab, size, begin);
}

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }

// // void  flood_fill(char **tab, t_point size, t_point begin)
// // {
// // 	int	y = 0;
// // 	int	x = 0;
// // 	char start = tab[begin.y][begin.x];

// // 	while (y < size.y)
// // 	{
// // 		x = 0;
// // 		while (x < size.x)
// // 		{
// // 			if (tab[y][x] == start)
// // 				tab[y][x] == 'F';
// // 			x++;
// // 		}
// // 		y++;
// // 	}
// // }

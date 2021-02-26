

#include "fillit.h"

int		figure_fits(t_figure *fig, t_map *map, int x, int y)
{
	int i;
	int size;

	i = 0;
	size = map->size;
	while (i < 4)
	{
		if (fig->x[i] + x >= size || fig->y[i] + y >= size)
			return (0);
		i++;
	}
	return (1);
}

int		figs_not_col(t_figure *fig, t_map *map, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map->symbol[y + fig->y[i]][x + fig->x[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	place_fig(t_figure *fig, t_map *map, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->symbol[y + fig->y[i]][x + fig->x[i]] = fig->order;
		i++;
	}
}

void	place_dot(t_figure *fig, t_map *map, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->symbol[y + fig->y[i]][x + fig->x[i]] = '.';
		i++;
	}
}

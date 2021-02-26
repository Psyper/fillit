

#include "fillit.h"

int		solve(t_figure *figure, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (figure == NULL)
		return (1);
	while (figure_fits(figure, map, j, i))
	{
		while (figure_fits(figure, map, j, i))
		{
			if (figs_not_col(figure, map, j, i))
			{
				place_fig(figure, map, j, i);
				if (solve(figure->next, map))
					return (1);
				else
					place_dot(figure, map, j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	solve_bigger_map(t_figure *figure, int count)
{
	t_map	*map;
	int		size;

	move_list(figure);
	map = create_map(calculate_min_map_size(count));
	size = map->size;
	while (!solve(figure, map))
	{
		free_map(map);
		size++;
		map = create_map(size);
	}
	print_map(map);
	free_map(map);
}

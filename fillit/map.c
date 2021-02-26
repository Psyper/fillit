

#include "fillit.h"

int		calculate_min_map_size(int count)
{
	int min;

	min = 2;
	while (min * min < count * 4)
	{
		min++;
	}
	return (min);
}

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->symbol = (char **)malloc(sizeof(char*) * size);
	map->size = size;
	while (i < size)
	{
		map->symbol[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			map->symbol[i][j] = '.';
			j++;
		}
		map->symbol[i][j] = '\0';
		j = 0;
		i++;
	}
	return (map);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		free(map->symbol[i]);
		i++;
	}
	free(map->symbol);
	free(map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->symbol[i]);
		i++;
	}
}

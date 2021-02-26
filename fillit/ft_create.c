

#include "fillit.h"

void		ft_fill(struct s_figure *list, char array[4][5], int count)
{
	char	*alphabet;
	int		xc;
	int		yc;
	int		j;
	int		i;

	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	list->order = alphabet[count];
	xc = 0;
	yc = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == '#')
			{
				list->x[xc++] = j;
				list->y[yc++] = i;
			}
			j++;
		}
		i++;
	}
}

void		ft_create(t_figure **list, char array[4][5], int count)
{
	t_figure *node;
	t_figure *tmp;

	if (array && count)
	{
		(void)array[4][5];
		(void)count;
	}
	node = malloc(sizeof(t_figure));
	node->next = NULL;
	if (*list == NULL)
		*list = node;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	ft_fill(node, array, count);
}

void		move_figure(t_figure *fig)
{
	int i;
	int min_x;
	int min_y;

	i = 0;
	min_x = 3;
	min_y = 3;
	while (i < 4)
	{
		if (fig->x[i] < min_x)
			min_x = fig->x[i];
		if (fig->y[i] < min_y)
			min_y = fig->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fig->x[i] = fig->x[i] - min_x;
		fig->y[i] = fig->y[i] - min_y;
		i++;
	}
}

void		move_list(t_figure *list)
{
	t_figure *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		move_figure(tmp);
		tmp = tmp->next;
	}
}

void		free_figure_list(t_figure *fig_list)
{
	t_figure *tmp;

	tmp = fig_list;
	while (fig_list != NULL)
	{
		tmp = fig_list->next;
		free(fig_list);
		fig_list = tmp;
	}
}

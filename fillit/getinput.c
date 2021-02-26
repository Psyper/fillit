

#include "fillit.h"

int	checkblock(char array[4][5])
{
	int i;
	int j;
	int m;
	int k;

	m = 0;
	i = 0;
	j = 0;
	k = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			(array[j][i] == '#') ? k++ : k;
			(i < 3 && array[j][i] == '#' && array[j][i + 1] == '#') ? m++ : m;
			(j < 3 && array[j][i] == '#' && array[j + 1][i] == '#') ? m++ : m;
			(i > 0 && array[j][i] == '#' && array[j][i - 1] == '#') ? m++ : m;
			(j > 0 && array[j][i] == '#' && array[j - 1][i] == '#') ? m++ : m;
			i++;
		}
		i = 0;
		j++;
	}
	m = (m >= 6 && k == 4) ? 1 : 0;
	return (m);
}

int	validarray(char (*array)[26][4][5], int n)
{
	int tet;

	tet = 0;
	while (tet < n)
	{
		if (!checkblock((*array)[tet]))
			return (0);
		tet++;
	}
	return (tet);
}

int	valid(char *line)
{
	int i;

	i = 0;
	if (line[4] != '\n')
		return (0);
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int	getinput(int fd, char (*input)[26][4][5])
{
	int		tet;
	int		str;
	char	tmp;

	str = 0;
	tet = 0;
	while (tet < 26 && read(fd, (*input)[tet][str], 5) > 0)
	{
		if (!valid((*input)[tet][str]))
			return (0);
		(*input)[tet][str][4] = 0;
		if (str == 3)
		{
			tmp = 0;
			read(fd, &tmp, 1);
			if (tmp != '\n' && tmp != 0)
				return (0);
			tet++;
			if (tmp == 0)
				return (validarray(input, tet));
		}
		(str == 3) ? (str = 0) : (str++);
	}
	return (0);
}

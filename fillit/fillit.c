

#include "fillit.h"

int		fillit(int fd)
{
	int			i;
	int			n;
	t_ret		retlist;
	char		input[26][4][5];

	if (!(n = getinput(fd, &input)))
		return (0);
	retlist.count = n;
	retlist.startlist = NULL;
	i = 0;
	while (i < n)
	{
		ft_create(&retlist.startlist, input[i], i);
		i++;
	}
	solve_bigger_map(retlist.startlist, retlist.count);
	free_figure_list(retlist.startlist);
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./valid valid_sample_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("error");
		return (0);
	}
	if (!(fillit(fd)))
	{
		ft_putstr("error");
		return (1);
	}
	return (0);
}

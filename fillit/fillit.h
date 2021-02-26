

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_figure
{
	int					x[4];
	int					y[4];
	char				order;
	struct s_figure		*next;
}						t_figure;

typedef	struct			s_ret
{
	struct s_figure		*startlist;
	int					count;
}						t_ret;

typedef	struct			s_map
{
	char				**symbol;
	int					size;
}						t_map;

int						fillit(int fd);
int						calculate_min_map_size(int count);
t_map					*create_map(int size);
void					free_map(t_map *map);
void					print_map(t_map *map);
void					solve_bigger_map(t_figure *figure, int count);
t_figure				*input_into_figure();
t_figure				*add_figure(t_figure *fig_list, t_figure *fig);
void					free_figure_list(t_figure *fig_list);
int						getinput(int fd, char (*input)[26][4][5]);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_create(t_figure **list, char array[4][5], int count);
void					move_list(t_figure *list);
void					free_figure_list(t_figure *fig_list);
int						figure_fits(t_figure *fig, t_map *map, int x, int y);
int						figs_not_col(t_figure *fig, t_map *map, int x, int y);
void					place_fig(t_figure *fig, t_map *map, int x, int y);
void					place_dot(t_figure *fig, t_map *map, int x, int y);

#endif

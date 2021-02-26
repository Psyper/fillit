

#include "fillit.h"

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s != '\0')
			ft_putchar(*s++);
		ft_putchar('\n');
	}
}

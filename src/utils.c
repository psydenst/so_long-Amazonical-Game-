#include "../inc/so_long.h"

int	get_height(fd)
{
	int	i;
    char    *str;

	i = 1;
    str = get_next_line(fd);
	while(str != 0)
    {
        str = get_next_line(fd);
		i++;
    }
	return (i - 1);
}

int	ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
#include "libft.h"

size_t		ft_strlench(const char *s, const char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
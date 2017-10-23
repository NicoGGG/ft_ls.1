#include "libft.h"
#include <stdlib.h>

char	*ft_strrenew(char *str, size_t new_size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (str == 0)
		return (ft_strnew(new_size));
	i = ft_strlen(str);
	if (new_size <= i)
		return (str);
	new = ft_strnew(new_size);
	new = ft_strncat(new, str, i);
	free(str);
	return (new);
}
#include "so_long_bonus.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (NULL);
	if (size != 0 && size > (SIZE_MAX / count))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*d;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	d = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*d;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	d = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!d)
		return (free(s1), NULL);
	if (s1)
		while (s1[i])
			d[j++] = s1[i++];
	j = 0;
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = '\0';
	return (free(s1), d);
}
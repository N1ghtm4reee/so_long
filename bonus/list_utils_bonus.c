#include "so_long_bonus.h"

int ft_strlen1(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

char	*ft_strdup1(const char *s)
{
	int		len;
	char	*d;
	int		i;

	len = ft_strlen1((char *)s);
	d = malloc(sizeof(char) * (len + 1));
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

int ft_lst_size(t_parse *lst)
{
    int size = 0;
    while(lst)
    {
        size++;
        lst = lst->next;
    }
    return size;
}

t_parse *ft_lst_new(char *line)
{
    t_parse *new;

	new = malloc(sizeof(t_parse));
	if (!new)
		return (NULL);
    new->line = ft_strdup1(line);
    new->next = NULL;
    return new;
}

void ft_lst_addback(t_parse **lst, char *line)
{
    t_parse	*p;
    t_parse *new = ft_lst_new(line);

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}

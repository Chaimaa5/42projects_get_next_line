/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:23:51 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/12/07 04:24:04 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*current_line(char *rest)
{
	int	i;

	i = 0;
	if (!rest[0])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	return (ft_substr(rest, 0, i + 1));
}

char	*next_line(char *rest)
{
	int		i;
	char	*x;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			x = ft_substr(rest, i + 1, ft_strlen(rest));
			free(rest);
			return (x);
		}
		i++;
	}
	free(rest);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest[OPEN_MAX];
	char			*line;
	int				c;

	c = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (c && ft_strchr(rest[fd]))
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c == -1)
			return (line);
		buff[c] = '\0';
		rest = ft_strjoin(rest[fd], buff);
	}
	line = current_line(rest[fd]);
	rest[fd] = next_line(rest[fd]);
	return (line);
}

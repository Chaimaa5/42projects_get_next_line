/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:24:41 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/12/07 04:24:42 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len2;
	int		i;
	int		len1;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		p[i - 1] = s1[i - 1];
	while (i++ < len1 + len2 + 1)
		p[i - 2] = s2[i - len1 - 2];
	p[len1 + len2] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*buff;

	i = 0;
	len = ft_strlen(s);
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (0);
	while (s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	free(s);
	return (buff);
}

char	*ft_substr(char	*s, int start, int len)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = len;
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s) || s[0] == '\0')
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

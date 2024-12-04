/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-mah <mben-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:18:30 by mouad             #+#    #+#             */
/*   Updated: 2024/12/04 20:26:07 by mben-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*duplicated;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	duplicated = (char *)malloc((str_len + 1) * sizeof(char));
	if (!duplicated)
		return (NULL);
	i = 0;
	while (str[i])
	{
		duplicated[i] = str[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	if (c == 0)
		return (ft_strdup(str));
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (joined);
}

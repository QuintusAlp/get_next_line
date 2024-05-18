/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:54:08 by qalpesse          #+#    #+#             */
/*   Updated: 2024/05/01 14:26:52 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_bn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_freestr(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		size_s1;
	int		size_s2;
	int		i;

	size_s1 = ft_strlen_bn(s1);
	size_s2 = ft_strlen_bn(s2);
	new_str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!new_str)
		return (ft_freestr(s1));
	i = -1;
	if (s1)
	{
		while (++i, i < size_s1)
			new_str[i] = s1[i];
		i--;
	}
	while (++i, i < size_s1 + size_s2)
		new_str[i] = s2[i - size_s1];
	new_str[i] = '\0';
	ft_freestr(s1);
	return (new_str);
}

int	ft_findchar(char c, char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

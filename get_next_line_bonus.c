/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:38:02 by qalpesse          #+#    #+#             */
/*   Updated: 2024/05/01 15:20:30 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_buffer_modif(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	j = 0;
	i += 1;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*ft_strverif(char *str)
{
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	else
		return (str);
}

void	ft_bzero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*str;
	char static	buffer[OPEN_MAX + 1][BUFFER_SIZE + 1];
	int			rd;

	if ((fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE < 0)
		return (NULL);
	rd = 1;
	str = NULL;
	while (rd > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (!str)
			return (NULL);
		if (ft_findchar('\n', buffer[fd]))
		{
			ft_buffer_modif(buffer[fd]);
			break ;
		}
		rd = read(fd, buffer[fd], BUFFER_SIZE);
		if (rd != -1)
			buffer[fd][rd] = '\0';
		else
			return (ft_bzero(buffer[fd], BUFFER_SIZE + 1), free(str), NULL);
	}
	return (ft_strverif(str));
}

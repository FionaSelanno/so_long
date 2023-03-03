/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:53:05 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/28 12:17:18 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*get_line(char *str)
{
	char	*line;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}	
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	is_eol(char *data)
{
	int	i;

	if (!data)
		return (0);
	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *buffer)
{
	char	*data;
	int		nbytes;

	data = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!data)
		return (NULL);
	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, data, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(data);
			return (NULL);
		}
		data[nbytes] = '\0';
		buffer = ft_strjoin(buffer, data);
		if (!buffer)
			return (NULL);
		if (is_eol(data) != 0)
			break ;
	}
	free(data);
	return (buffer);
}

char	*update_buffer(char *str, char *substr)
{
	char	*updated;
	int		len_str;
	int		len_substr;
	int		i;

	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	len_substr = ft_strlen(substr);
	len_str = ft_strlen(str);
	updated = malloc(sizeof(char) * (len_str - len_substr) + 1);
	if (!updated)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[len_substr])
		updated[i++] = str[len_substr++];
	updated[i] = '\0';
	free(str);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("ERROR");
	buffer = read_file(fd, buffer);
	if (!buffer)
		return ("ERROR");
	line = get_line(buffer);
	buffer = update_buffer(buffer, line);
	return (line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:04:53 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/18 15:47:12 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str_gnl(char **str, char **buffer, int *bytes_read, int fd)
{
	while (*bytes_read > 0)
	{
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(**buffer));
		if (*buffer == NULL)
			return (free_all(str, NULL));
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (free_all(buffer, str));
		*str = strappend(str, buffer);
		if (*str == NULL)
			return (NULL);
		if (check_nl(*str))
			return (*str);
	}
	return (*str);
}

char	*strappend(char **str, char **buffer)
{
	char	*strappend;
	int		i;
	int		j;

	if (*str == NULL)
	{
		strappend = ft_strcpy(buffer);
		if (strappend == NULL)
			return (NULL);
		return (strappend);
	}
	i = ft_strlen(*str);
	j = ft_strlen(*buffer);
	strappend = ft_calloc(i + j + 1, sizeof(*strappend));
	if (strappend == NULL)
		return (free_all(str, buffer));
	i = -1;
	while ((*str)[++i] != '\0')
		strappend[i] = (*str)[i];
	j = -1;
	while ((*buffer)[++j] != '\0')
		strappend[i++] = (*buffer)[j];
	free_all(str, buffer);
	return (strappend);
}

char	*fetch_line(char **str)
{
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(*line));
	if (line == NULL)
		return (free_all(str, NULL));
	i = -1;
	while ((*str)[++i] != '\n' && (*str)[i] != '\0')
		line[i] = (*str)[i];
	if ((*str)[i] == '\n')
		line[i] = '\n';
	*str = update_str(str);
	if (*str == NULL)
		return (free_all(&line, NULL));
	return (line);
}

char	*update_str(char **str)
{
	char	*update;
	int		i;
	int		j;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
		i++;
	j = i;
	i = ft_strlen(*str + i);
	update = ft_calloc(i + 1, sizeof(*update));
	if (update == NULL)
		return (free_all(str, NULL));
	i = -1;
	while ((*str)[j] != '\0')
		update[++i] = (*str)[j++];
	free_all(str, NULL);
	return (update);
}

char	*ft_strcpy(char **buffer)
{
	char	*strcpy;
	int		i;

	i = ft_strlen(*buffer);
	strcpy = ft_calloc(i + 1, sizeof(*strcpy));
	if (strcpy == NULL)
		return (free_all(buffer, NULL));
	i = -1;
	while ((*buffer)[++i] != '\0')
		strcpy[i] = (*buffer)[i];
	free_all(buffer, NULL);
	return (strcpy);
}

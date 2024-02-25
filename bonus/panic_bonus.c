/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:11:53 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/24 15:32:59 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	panic_free(char *msg, char **str, char *str2, int exit_status)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	if (str2)
		free(str2);
	if (msg)
		panic(msg, NULL, NULL, exit_status);
}

void	panic(char *msg, int **fd, char *str, int exit_status)
{
	int	len;

	if (fd)
	{
		close_pipes(fd);
		free_pipes(fd);
	}
	if (str)
		free(str);
	if (msg)
	{
		len = ft_strlen(msg);
		write(2, msg, len);
	}
	exit(exit_status);
}

void	close_pipes(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	free_pipes(int	**fd)
{
	int	i;

	i = -1;
	while (fd[++i])
		free(fd[i]);
	free(fd);
}

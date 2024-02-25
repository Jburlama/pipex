/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:43:11 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/25 15:47:28 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	prints msg to stderr
	closes the pipes
	and the file descripter associated with a file
	exit the process with the exit_code
*/
void	panic(char	*msg, int *fd, int file, int exit_code)
{
	int	len;

	if (msg)
	{
		len = ft_strlen(msg);
		write(2, msg, len);
	}
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (file >= 0)
		close(file);
	exit(exit_code);
}

/*
	if recieve msg sends to panic whit exit_code
	free str and str2
*/
void	panic_free(char *msg, char	**str, char *str2, int exit_code)
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
		panic(msg, NULL, -1, exit_code);
}

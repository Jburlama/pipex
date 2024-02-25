/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:04:45 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/24 15:14:29 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	**fd;
	int	pid;
	int	i;

	if (argc < 5)
		panic("Invalid number of arguments!\n", NULL, NULL, 1);
	fd = creat_pipes(argc - 4);
	i = -1;
	while (++i < argc - 4)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				input(argv, envp, fd);
			else
				execute(i, argv, envp, fd);
		}
	}
	output(argc, argv, envp, fd);
}

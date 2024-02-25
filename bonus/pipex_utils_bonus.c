/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:20:41 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/24 15:33:20 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	execute(int i, char **argv, char **envp, int **fd)
{
	char	*path;
	char	**cmd;

	if (dup2(fd[i - 1][0], 0) == -1 || dup2(fd[i][1], 1) == -1)
		panic("Error calling dup2 in execute!\n", fd, NULL, 1);
	close_pipes(fd);
	path = ft_strcut(argv[i + 2], ' ');
	if (path == NULL)
		panic("Error calling ft_strcut in execut!\n", NULL, NULL, 1);
	path = get_path(path, envp);
	cmd = get_cmd(argv[i + 2]);
	if (cmd == NULL)
		panic_free("Error calling get_cmd in execute!\n", NULL, path, 1);
	if (access(path, X_OK) == 0)
	{
		if (execve(path, cmd, envp) == -1)
			panic_free("Error calling execve in execetu!\n", cmd, path, 1);
		panic_free("Command not found!\n", cmd, path, 127);
	}
}

void	input(char **argv, char **envp, int **fd)
{
	int		infile;
	char	*path;
	char	**cmd;

	if (ft_memcmp(argv[1], "here_doc", 8) == 0)
		here_doc_input(argv[2], fd);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		panic("Error opening infile in input!\n", fd, NULL, 1);
	if (dup2(infile, 0) == -1 || dup2(fd[0][1], 1) == -1)
		panic("Error calling dup2 in output!\n", fd, NULL, 1);
	close(infile);
	close_pipes(fd);
	path = ft_strcut(argv[2], ' ');
	if (path == NULL)
		panic("Error calling ft_strcut in input!\n", NULL, NULL, 1);
	path = get_path(path, envp);
	cmd = get_cmd(argv[2]);
	if (cmd == NULL)
		panic("Error calling get_cmd in input!\n", NULL, path, 1);
	if (execve(path, cmd, envp) == -1)
		panic_free("Error calling execve in input!\n", cmd, path, 1);
	panic_free("Command not found!\n", cmd, path, 127);
}

void	here_doc_input(char *limiter, int **fd)
{
	char	*line;

	if (dup2(fd[0][1], 1) == -1)
		panic("Error calling dup2 in here_doc_input!\n", fd, NULL, 1);
	while (42)
	{
		line = get_next_line(0);
		if (ft_memcmp(limiter, line, ft_strlen(line) - 1) == 0)
			break ;
		write(fd[0][1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close_pipes(fd);
	exit(0);
}

void	output(int argc, char **argv, char **envp, int **fd)
{
	int		outfile;
	char	*path;
	char	**cmd;

	if (ft_memcmp(argv[1], "here_doc", 8) == 0)
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0755);
	else
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (outfile == -1)
		panic("Error opening outfile!\n", fd, NULL, 1);
	if (dup2(fd[argc - 4 - 1][0], 0) == -1 || dup2(outfile, 1) == -1)
		panic("Error calling dup2 in output!\n", fd, NULL, 1);
	close(outfile);
	close_pipes(fd);
	path = ft_strcut(argv[argc - 2], ' ');
	if (path == NULL)
		panic("Error calling ft_strcut in output!\n", NULL, NULL, 1);
	path = get_path(ft_strcut(path, ' '), envp);
	cmd = get_cmd(argv[argc - 2]);
	if (cmd == NULL)
		panic("Error calling get_cmd in output!\n", NULL, path, 1);
	if (execve(path, cmd, envp) == -1)
		panic_free("Error calling execve in output!\n", cmd, path, 1);
	panic_free("Command not found!\n", cmd, path, 127);
}

int	**creat_pipes(int pipe_number)
{
	int	**fd;
	int	i;

	fd = ft_calloc(sizeof(*fd), pipe_number + 1);
	if (fd == NULL)
		panic("Error allocating memory for pipes!\n", NULL, NULL, 1);
	i = -1;
	while (++i < pipe_number)
	{
		fd[i] = ft_calloc(sizeof(*fd[i]), 2);
		if (fd[i] == NULL)
		{
			while (++i < pipe_number)
				free(fd[i]);
			free_pipes(fd);
			panic("Error creating pipes!\n", NULL, NULL, 1);
		}
	}
	i = -1;
	while (++i < pipe_number)
		pipe(fd[i]);
	return (fd);
}

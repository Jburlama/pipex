/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:06:39 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/25 15:44:02 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	check for valid number of arguments and open pipe
	for the proccess
		if is child
			read from input and execute command and output to the parent
		if is parent
			read the output from the child and output to the outfile
			
*/
int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid;

	if (argc != 5 || pipe(fd) == -1)
		panic("Invalid arguments number!\n", NULL, -1, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		panic("Error calling fork!\n", fd, -1, EXIT_FAILURE);
	if (pid == 0)
	{
		input_output(argv[1], NULL, fd);
		execute(argv[2], envp);
	}
	input_output(NULL, argv[4], fd);
	execute(argv[3], envp);
}

/*
	finds the path and the arguments to execute the command
*/
void	execute(char *cmd_arg, char *envp[])
{
	char	*path;
	char	**cmd;

	path = ft_strcut(cmd_arg, ' ');
	if (path == NULL)
		panic("Error calling ft_strcut in child!\n", NULL, -1, 1);
	path = get_path(path, envp);
	cmd = get_cmd(cmd_arg);
	if (cmd == NULL)
		panic_free("Error calling get_cmd in child!\n", NULL, path, 1);
	if (access(path, X_OK) == 0)
	{
		if (execve(path, cmd, envp) == -1)
			panic_free("Error calling execve in child!\n", cmd, path, 1);
	}
	panic_free("Cammand not found!\n", cmd, path, 127);
}

/*
	if recieves input
		redirect the stdin from the input file and
		 the stdout to the write end of the pipe
	if recieves output
		redirect the stdin from the read end of the pipe and
		 the stdout to the output file
*/
void	input_output(char *input, char *output, int *fd)
{
	int	in;
	int	out;

	if (input)
	{
		in = open(input, O_RDONLY);
		if (in == -1)
			panic("Error opening input!\n", fd, -1, EXIT_FAILURE);
		if (dup2(in, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
			panic("Error, calling dup2 in input!\n", fd, in, EXIT_FAILURE);
		close(fd[0]);
		close(fd[1]);
		close(in);
	}
	if (output)
	{
		out = open(output, O_CREAT | O_TRUNC | O_WRONLY, 0755);
		if (out == -1)
			panic("Error opening output!\n", fd, -1, EXIT_FAILURE);
		if (dup2(out, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
			panic("Error, calling dup2 in output!\n", fd, out, EXIT_FAILURE);
		close(fd[0]);
		close(fd[1]);
		close(out);
	}
}

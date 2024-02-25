/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:10:03 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/24 15:30:32 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../libft/libft.h"

//utils
void	execute(int i, char **argv, char **envp, int **fd);
void	input(char **argv, char **envp, int **fd);
void	here_doc_input(char *limiter, int **fd);
void	output(int argc, char **argv, char **envp, int **fd);
int		**creat_pipes(int pipe_number);

// path.c
char	*get_path(char *path, char **envp);
char	**get_env_paths(char **envp);
char	*get_valid_path(char **paths);

// cmd.c
char	**get_cmd(char *parameters);
int		get_parameters_count(char *parameters);
char	*get_cmd_arg(char *parameters, int *i);
char	*get_cmd_quotes(char *parameters, int *i);

// panic
void	panic_free(char *msg, char **str, char *str2, int exit_status);
void	panic(char *msg, int **fd, char *str, int exit_status);
void	close_pipes(int **fd);
void	free_pipes(int	**fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:04:54 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/24 14:40:51 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "../libft/libft.h"

void	input_output(char *input, char *output, int *fd);
void	execute(char *cmd, char *envp[]);

// utils
void	panic(char	*msg, int *fd, int file, int exit_code);
void	panic_free(char *msg, char	**str, char *str2, int exit_code);

// path.c
char	*get_path(char *path, char **envp);
char	**get_env_paths(char **envp);
char	*get_valid_path(char **paths);

// cmd.c
char	**get_cmd(char *parameters);
int		get_parameters_count(char *parameters);
char	*get_cmd_arg(char *parameters, int *i);
char	*get_cmd_quotes(char *parameters, int *i);

#endif

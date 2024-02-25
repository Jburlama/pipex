/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 06:54:05 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/25 15:58:18 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

// returns the binary path to execute the command
char	*get_path(char *path, char **envp)
{
	int		i;
	char	**env_paths;
	char	*temp;

	i = -1;
	env_paths = get_env_paths(envp);
	if (env_paths == NULL)
		panic("Error calling get_env_paths!\n", NULL, path, 1);
	while (env_paths[++i])
	{
		temp = ft_strjoin(env_paths[i], "/");
		if (temp == NULL)
			panic_free("Error calling ft_strjoin!\n", env_paths, path, 1);
		free(env_paths[i]);
		env_paths[i] = ft_strjoin(temp, path);
		free(temp);
		if (env_paths[i] == NULL)
		{
			while (env_paths[++i])
				free(env_paths[i]);
			panic_free("Error calling ft_strjoin!\n", env_paths, path, 1);
		}
	}
	free(path);
	return (get_valid_path(env_paths));
}

/*
	 takes the envirement pointer as a argument
		and returns all the diverent paths from it
*/
char	**get_env_paths(char **envp)
{
	int		i;
	char	**env_paths;
	char	*temp;

	i = 0;
	while (ft_memcmp(envp[i], "PATH=", 5) != 0)
		i++;
	env_paths = ft_split(envp[i], ':');
	if (env_paths == NULL)
		return (NULL);
	temp = env_paths[0];
	env_paths[0] = ft_strdup(env_paths[0] + 5);
	if (env_paths[0] == NULL)
	{
		i = 0;
		while (env_paths[++i])
			free(env_paths[i]);
		free(env_paths);
		free(temp);
		return (NULL);
	}
	free(temp);
	return (env_paths);
}

/*
	checks for the diferent paths and returns
	the one that the user can have access and execute
*/
char	*get_valid_path(char **paths)
{
	int		i;
	char	*path;

	i = -1;
	while (paths[++i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			path = ft_strdup(paths[i]);
			break ;
		}
	}
	if (paths[i] == NULL)
		panic_free("Invalid command!\n", paths, NULL, 127);
	else
	{
		i = -1;
		while (paths[++i])
			free(paths[i]);
		free(paths);
	}
	return (path);
}

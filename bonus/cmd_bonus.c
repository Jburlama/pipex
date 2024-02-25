/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:08:15 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/25 15:57:43 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
	recieves the parameters of a command and split the
	in to a argument vector
*/
char	**get_cmd(char *parameters)
{
	int		count;
	int		index;
	int		i;
	char	**cmd;

	count = get_parameters_count(parameters);
	cmd = ft_calloc(sizeof(*cmd), count + 1);
	if (cmd == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < count)
	{
		cmd[i] = get_cmd_arg(parameters, &index);
		if (cmd[i] == NULL)
		{
			i = 0;
			while (cmd[i])
				free(cmd[i]);
			free(cmd);
			return (NULL);
		}
		i++;
	}
	return (cmd);
}

// checks for the number of parameters
int	get_parameters_count(char *parameters)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (parameters[++i])
	{
		count++;
		while (parameters[i] != ' ' && parameters[i] != 39 && parameters[i])
			i++;
		if (parameters[i] == 39)
		{
			i++;
			while (parameters[i] != 39 && parameters[i])
				i++;
			if (parameters[i] == 39)
				i++;
			while (parameters[i + 1] == ' ' && parameters[i])
				i++;
		}
		if (!parameters[i])
			break ;
	}
	return (count);
}

// return the arguments from the parmeters individualy
char	*get_cmd_arg(char *parameters, int *i)
{
	int			index;
	int			len;
	char		*arg;

	len = 0;
	if (parameters[*i] == 39)
		return (get_cmd_quotes(parameters, i));
	while (parameters[*i] != ' ' && parameters[*i])
	{
		(*i)++;
		len++;
	}
	arg = ft_calloc(sizeof(*arg), len + 1);
	if (arg == NULL)
		return (NULL);
	index = *i;
	while (len-- >= 0)
		arg[len + 1] = parameters[index--];
	while (parameters[*i] == ' ' && parameters[*i])
		(*i)++;
	return (arg);
}

// gets called if the argument for the command is inside quotes
char	*get_cmd_quotes(char *parameters, int *i)
{
	char	*arg;
	int		len;
	int		index;

	len = 0;
	(*i)++;
	while (parameters[*i] != 39 && parameters[*i])
	{
		len++;
		(*i)++;
	}
	if (!parameters[*i])
		return (ft_strdup(parameters + (*i) - len - 1));
	arg = ft_calloc(sizeof(*arg), len + 1);
	if (arg == NULL)
		return (NULL);
	index = (*i) - 1;
	while (len-- >= 0)
		arg[len] = parameters[index--];
	if (parameters[*i] == 39)
		(*i)++;
	while (parameters[(*i)] == ' ' && parameters[(*i)])
		(*i)++;
	return (arg);
}

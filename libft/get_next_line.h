/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:05:27 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/18 15:46:17 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*free_all(char **s1, char **s2);
int		check_nl(char *str);
char	*ft_strcpy(char **buffer);
char	*get_str_gnl(char **str, char **buffer, int *bytes_read, int fd);
char	*strappend(char **str, char **buffer);
char	*fetch_line(char **str);
char	*update_str(char **str);

#endif

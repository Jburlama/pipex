/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:08:25 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/10 18:02:16 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(char const *s, char c);
int		chrcmp(char s, char c);
char	*get_word(char const *s, char c);
char	**ft_free(char **split);

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	int		i;
	int		j;

	words = count_words(s, c);
	split = ft_calloc(sizeof(char *), words + 1);
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (chrcmp(s[j], c) == 1 && s[j] != '\0')
			j++;
		split[i] = get_word(s + j, c);
		if (split[i] == NULL)
			return (ft_free(split));
		while (chrcmp(s[j], c) == 0 && s[j] != '\0')
			j++;
		i++;
	}
	split[words] = NULL;
	return (split);
}

char	*get_word(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (chrcmp(s[i], c) == 0 && s[i] != '\0')
		i++;
	word = ft_calloc(sizeof(char), i + 1);
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

int	chrcmp(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (chrcmp(s[i], c) == 1 && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (chrcmp(s[i], c) == 0 && s[i] != '\0')
			i++;
		words++;
		while (chrcmp(s[i], c) == 1 && s[i] != '\0')
			i++;
	}
	return (words);
}

char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

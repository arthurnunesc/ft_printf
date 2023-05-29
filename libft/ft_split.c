/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:47:01 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/19 16:44:20 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*ft_clean(char **char_ptr_ptr, size_t failed_index)
{
	while (failed_index > 0)
		free(char_ptr_ptr[--failed_index]);
	free(char_ptr_ptr);
	return (NULL);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_extractword(char const *s, char sep, size_t *start)
{
	size_t	end;
	char	*word;

	while (s[*start] == sep)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != sep)
		end++;
	word = ft_substr(s, *start, end - *start);
	*start = end;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;
	size_t	i;
	size_t	start;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = 0;
	word_count = ft_countwords(s, c);
	split = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < word_count)
	{
		split[i] = ft_extractword(s, c, &start);
		if (split[i] == NULL)
			return (ft_clean(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}

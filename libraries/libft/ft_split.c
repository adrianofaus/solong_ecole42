/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:07:39 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:07:40 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(const char *s, char c)
{
	int	w;
	int	flag;

	w = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			w++;
			flag = 1;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (w);
}

static char	*ft_gen(const char *begin, char c)
{
	char	*word;
	int		end;
	int		i;

	end = 0;
	while (begin[end] != c && begin[end])
		end++;
	word = (char *)malloc(end * sizeof(char) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (begin[i] != c && i < end)
	{
		word[i] = begin[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		reset;
	int		i;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_nwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	reset = 0;
	while (*s)
	{
		if (*s == c)
			reset = 0;
		if (*s != c && !reset)
		{
			arr[i] = ft_gen(s, c);
			i++;
			reset = 1;
		}
		s++;
	}
	arr[i] = NULL;
	return (arr);
}

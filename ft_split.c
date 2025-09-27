/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:35:40 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/27 16:16:49 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, unsigned char delim)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (unsigned char)s[i] == delim)
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && (unsigned char)s[i] != delim)
			i++;
	}
	return (count);
}

static char	**free_split(char **arr, size_t used)
{
	while (used > 0)
		free(arr[--used]);
	free(arr);
	return (NULL);
}

static char	*dup_segment(const char *ptr, size_t len)
{
	char	*s;

	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	if (len > 0)
		ft_memcpy(s, ptr, len);
	s[len] = '\0';
	return (s);
}

static int	fill_split(char **out, const char *s, unsigned char c, size_t *used)
{
	size_t	k;
	size_t	len;

	k = 0;
	while (*s)
	{
		while (*s && (unsigned char)*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && (unsigned char)s[len] != c)
			len++;
		out[k] = dup_segment(s, len);
		if (!out[k])
		{
			*used = k;
			return (-1);
		}
		k++;
		s += len;
	}
	out[k] = (NULL);
	*used = k;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	n;
	size_t	used;

	if (!s)
		return (NULL);
	n = count_words(s, (unsigned char)c);
	if (n > SIZE_MAX / sizeof(char *) - 1)
		return (NULL);
	out = (char **)malloc((n + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	if (fill_split(out, s, (unsigned char)c, &used) < 0)
		return (free_split(out, used));
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:41:06 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/24 20:43:55 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*l;
	unsigned char	uc;

	l = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == uc)
			l = (char *) s;
		s++;
	}
	if (uc == '\0')
		return ((char *) s);
	return (l);
}

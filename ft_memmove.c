/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:45:44 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/27 19:21:21 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (unsigned char *) dst;
	p2 = (unsigned char *) src;
	if (p1 == p2 || n == 0)
		return (dst);
	if (p1 < p2)
	{
		return (ft_memcpy(dst, src, n));
	}
	else
	{
		i = n;
		while (i > 0)
		{
			p1[i - 1] = p2[i - 1];
			i--;
		}
	}
	return (dst);
}

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

static void	ft_memcpy_forward(unsigned char *dst, const unsigned char *src,
			size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	ft_memcpy_backward(unsigned char *dst, const unsigned char *src,
			size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	if (!dst && !src && n > 0)
		return (NULL);
	if (dst == src || n == 0)
		return (dst);
	p1 = (unsigned char *) dst;
	p2 = (const unsigned char *) src;
	if (p1 < p2)
		ft_memcpy_forward(p1, p2, n);
	else
		ft_memcpy_backward(p1, p2, n);
	return (dst);
}

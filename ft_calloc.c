/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:56:11 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/25 23:11:57 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t;
	void	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	t = nmemb * size;
	p = malloc(t);
	if (!p)
		return (NULL);
	ft_bzero(p, t);
	return (p);
}

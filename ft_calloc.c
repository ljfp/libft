/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:56:11 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/25 23:48:28 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if t == 0 we have to still create a pointer because of a
// stupid rule in the subject.
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t;
	void	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	t = nmemb * size;
	if (t == 0)
		t = 1;
	p = malloc(t);
	if (!p)
		return (NULL);
	ft_bzero(p, t);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:18:40 by lauferna          #+#    #+#             */
/*   Updated: 2025/09/27 16:26:05 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	write_digits(char *dst, size_t len, long n)
{
	while (len > 0)
	{
		dst[len - 1] = (char)('0' + (n % 10));
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	int		is_neg;
	char	*s;

	nb = (long) n;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	len = int_len(nb);
	s = (char *)malloc(len + is_neg + 1);
	if (!s)
		return (NULL);
	if (is_neg)
		s[0] = '-';
	write_digits(s + is_neg, len, nb);
	s[len + is_neg] = '\0';
	return (s);
}

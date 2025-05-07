/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:03:00 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 16:03:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Helper function for forward copying (d < s)
static void	*ft_forward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// Helper function for backward copying (d > s)
static void	*ft_backward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (d);
}

// Main memmove function
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (d < s)
		ft_forward(d, s, len);
	else if (d > s)
		ft_backward(d, s, len);
	return (dst);
}

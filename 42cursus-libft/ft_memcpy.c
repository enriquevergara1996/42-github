/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:56:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 15:56:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	const unsigned char	*s;
	unsigned long		i;
	unsigned char		*d;

	if (!dst && !src)
		return ((void *)0);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
		d[i] = s[i++];
	return (dst);
}

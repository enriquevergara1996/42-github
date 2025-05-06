/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:44:05 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 15:44:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*p;
	unsigned long	i;

	*p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i++] = (unsigned char)c;
	}
	return (b);
}

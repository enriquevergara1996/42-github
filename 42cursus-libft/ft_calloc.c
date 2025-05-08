/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:34:43 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 16:34:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  Devuelve NULL si count * size desborda size_t  */
static int	overflow(size_t count, size_t size)
{
	if (size != 0 && count > ((size_t)-1) / size)
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (overflow(count, size))
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	if (total)
		ft_bzero(ptr, total);
	return (ptr);
}

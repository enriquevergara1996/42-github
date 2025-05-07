/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:38:33 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 16:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

// Función estática que crea una cadena vacía
static char	*empty_string(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		str[0] = '\0';
	return (str);
}

// Función estática que realiza la copia substring
static char	*copy_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// Función pública ft_substr
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (empty_string());
	if (len > s_len - start)
		len = s_len - start;
	return (copy_substr(s, start, len));
}

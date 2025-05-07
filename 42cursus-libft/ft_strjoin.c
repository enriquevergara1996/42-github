/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:35:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 16:35:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

// Function to allocate memory for the joined string
static char	*fjoin(char const *s1, char const *s2, size_t *len1, size_t *len2)
{
	if (!s1 || !s2)
		return (NULL);
	*len1 = ft_strlen(s1);
	*len2 = ft_strlen(s2);
	return ((char *)malloc(*len1 + *len2 + 1));
}

// Main function to join two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*join;

	join = fjoin(s1, s2, &len1, &len2);
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		join[len1 + i] = s2[i];
		i++;
	}
	join[len1 + len2] = '\0';
	return (join);
}

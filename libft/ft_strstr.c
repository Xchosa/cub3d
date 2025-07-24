/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:58:33 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/24 10:59:43 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0'))
	{
		if ((ft_strncmp(haystack + i, needle, needle_len) == 0))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

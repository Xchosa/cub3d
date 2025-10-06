/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_array_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:20:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:30:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
takes a 2D array and returns a 2D array
*/

char	**ft_cpy_array_str(char	**arrays)
{
	char	**new_array;
	int		i;

	i = 0;
	if (!arrays)
		return (NULL);
	while (arrays[i] != NULL)
		i++;
	new_array = (char **)malloc((i + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (arrays[i] != NULL)
	{
		new_array[i] = ft_strdup(arrays[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

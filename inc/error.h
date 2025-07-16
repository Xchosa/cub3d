/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:33 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/16 17:09:17 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	enum	e_error
{
	ARGUMENT_AMOUNT = 1,
	WRONG_FILE_TYPE = 2,
	OPEN_FAILED		= 3,
	MALLOC_FAIL		= 4,
}				t_error;

void	ft_error( int error_code );
void	ft_error_msg( int error_code, char *msg );

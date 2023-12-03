/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 13:05:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/26 00:40:22 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_nl(char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

void	ft_copy_magic(t_concat_vars *x, int bufflen, char *buff)
{
	while (x->j < bufflen && buff[x->j] != '\0' && !x->found)
	{
		x->new[x->i] = buff[x->j];
		if (x->new[x->i] == '\n')
			x->found = 1;
		x->i++;
		x->j++;
	}
}

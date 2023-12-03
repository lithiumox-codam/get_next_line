/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 13:05:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/03 01:11:11 by lithium       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief A simple strchr that only looks for '\n'.
 *
 * @param str The string to search.
 * @param length The length of the string. (The remaining length of the buffer)
 * @return char* The pointer to the first '\n' in the string.
 */
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

/**
 * @brief A scuffed memcpy that copies the remaining buffer to the beginning.
 *
 * @param x The struct containing the concat variables.
 * @param bufflen The length of the buffer.
 * @param buff The buffer to copy from.
 */
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

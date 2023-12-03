/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 16:06:21 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/03 01:14:15 by lithium       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# if !defined(BUFFER_SIZE)
#  define BUFFER_SIZE 100
# endif // BUFFER_SIZE

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // BUFFER_SIZE

/**
 * @brief The struct containing the buffer and its length.
 *
 * @note This is made static so it can be used in multiple function calls.
 * @param buff The buffer. (Size is defined by BUFFER_SIZE)
 * @param length The current length of the buffer. Amount can vary from
 * The BUFFER_SIZE to any remainder of the buffer from a previous call.
 */
typedef struct s_gnl_buffer
{
	char	buff[BUFFER_SIZE];
	int		length;
}			t_gnl_buffer;

/**
 * @brief Scuffed struct that makes the code smaller not perticularly
 * clearer.
 *
 * @warning PLEASE DO NOT USE THIS IN YOUR CODE. IT IS NOT GOOD PRACTICE.
 */
typedef struct s_concat_vars
{
	size_t	size;
	char	*new;
	int		i;
	int		j;
	int		found;
}			t_concat_vars;

char		*get_next_line(int fd);
void		ft_copy_magic(t_concat_vars *x, int bufflen, char *buff);
void		get_remaining_buff(t_gnl_buffer *buffer);
char		*ft_strchr_nl(char *str, int length);
#endif

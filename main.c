/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 11:37:25 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/26 00:31:02 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool	streq(char *str1, char *str2)
{
	bool	equal;

	equal = false;
	if (strcmp(str1, str2) == 0)
		equal = true;
	free(str1);
	return (equal);
}

void	check_leaks(void)
{
	system("leaks -q gnl.out");
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("tests/giant.txt", O_RDONLY);
	while (i++ < 20)
		printf("%s", get_next_line(fd));
	return (0);
}

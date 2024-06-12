/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:30:56 by chrrodri          #+#    #+#             */
/*   Updated: 2024/06/12 14:08:34 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

void	display_file(const char *filename)
{
	int			file;
	char		buf[BUFFER_SIZE];
	ssize_t		b_read;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		write (2, "Cannot read file.\n", 18);
		return ;
	}
	b_read = read(file, buf, BUFFER_SIZE);
	while (b_read > 0)
	{
		if (b_read <= 0)
			break;
		else
			write(1, buf, b_read);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else
		display_file(argv[1]);
	return (0);
}

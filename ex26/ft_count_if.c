/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:11:24 by chrrodri          #+#    #+#             */
/*   Updated: 2024/06/10 17:07:32 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int	ft_check_content(char *str)
	return (*str != '\0') 

int	ft_count_if(char **tab, int (*f)(char*));

int	main(void)
{
	int	count;

	char *arr[] = {"1", "", "24", "x", "12365", "e3"}; 
	count = ft_count_if(arr, &ft_check_content);
	ft_putnbr(&count);
	return (0);
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (tab[i] != NULL) 
	{
		if ((*f)(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
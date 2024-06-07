//
// Created by christian on 27/04/24.
//
#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putnbr(int nbr)
{
    if (nbr < 0) {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + '0');
}

int ft_atoi(char *str)
{
    int i;
    int sign;
    int nbr;

    i = 0;
    sign = 1;
    nbr = 0;
    if (str[i] == '\0')
        write (2, "Error, no input!\n", 17);
    while (str[i] < 33)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58)
    {
        if (nbr == 0)
            nbr = str[i] - 48;
        else
            nbr = (nbr * 10) + (str[i] - 48);
        i++;
    }
    return (sign * nbr);
}

void    ft_putstr (char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
	i++;
    }
}

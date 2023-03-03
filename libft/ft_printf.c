/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:33:10 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 11:03:34 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	return (len);
}

int	ft_putnbr(long int nbr, int len)
{
	if (nbr < 0)
	{
		len += ft_putchar_printf('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		len = ft_putnbr(nbr / 10, len);
		len = ft_putnbr(nbr % 10, len);
	}
	else
		len += ft_putchar_printf(nbr + '0');
	return (len);
}

int	ft_parse(va_list buffer, char tag)
{
	if (tag == 'c')
		return (ft_putchar_printf(va_arg(buffer, int)));
	else if (tag == 's')
		return (ft_putstr(va_arg(buffer, char *)));
	else if (tag == 'd')
		return (ft_putnbr(va_arg(buffer, int), 0));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	buffer;

	i = 0;
	len = 0;
	va_start(buffer, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar_printf(str[i]);
		else if (str[i] == '%')
		{
			if (ft_strchr("csd", str[i + 1]) != 0)
			{
				len += ft_parse(buffer, str[i + 1]);
				i++;
			}
		}
		i++;
	}
	va_end(buffer);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:05:36 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/28 14:16:38 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1_conv;
	unsigned char	*str2_conv;

	i = 0;
	str1_conv = (unsigned char *)str1;
	str2_conv = (unsigned char *)str2;
	if (n == 0)
		return (0);
	if (!str1_conv)
		return (2);
	while (str1_conv[i] || str2_conv[i])
	{
		if (str1_conv[i] != str2_conv[i])
			return (1);
		i++;
	}
	return (0);
}
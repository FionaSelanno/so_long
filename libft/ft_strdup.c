/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:34:14 by fiselann          #+#    #+#             */
/*   Updated: 2022/12/08 16:34:28 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		strlen;

	strlen = ft_strlen(str);
	copy = malloc(sizeof(*copy) * strlen + 1);
	if (!copy)
		return (NULL);
	else
	{
		copy = ft_memcpy(copy, str, strlen);
		copy[strlen] = '\0';
		return (copy);
	}
}
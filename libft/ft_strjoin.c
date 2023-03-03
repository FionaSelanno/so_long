/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:18:49 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/22 15:07:19 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoined;
	int		len_strjoined;
	int		i;
	int		j;

	len_strjoined = ft_strlen(s1) + ft_strlen(s2);
	strjoined = malloc(sizeof(*strjoined) * (len_strjoined + 1));
	if (!strjoined)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		strjoined[i] = s1[i];
		i++;
	}	
	j = 0;
	free(s1);
	while (s2 && s2[j])
		strjoined[i++] = s2[j++];
	strjoined[i] = '\0';
	return (strjoined);
}

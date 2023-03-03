/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:58:21 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/22 13:59:08 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s)) //then there is no char's to substitute
		len = 0;
	if (ft_strlen(&s[start]) < len) //in case off the length of the string to substitute is smaller then te given len
 		len = ft_strlen(&s[start]);
	substr = malloc(sizeof(*substr) * len + 1);
	if (!substr)
		return (NULL);
	if (start >= ft_strlen(s))
		substr[0] = '\0';
	else
	{
		while (len > 0)
		{
			substr[i++] = s[start++];
			len--;
		}
		substr[i] = '\0';
	}
	return (substr);
}
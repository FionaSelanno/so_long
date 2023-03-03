/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:23:22 by fiselann          #+#    #+#             */
/*   Updated: 2022/12/09 09:23:25 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_conv;
	char	*src_conv;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_conv = (char *)dst;
	src_conv = (char *)src;
	while (n > 0)
	{
		*(dst_conv++) = *(src_conv++);
		n--;
	}
	return (dst);
}
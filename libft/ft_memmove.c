/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:29:41 by ialashqa          #+#    #+#             */
/*   Updated: 2024/09/20 19:30:25 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_p;
	char	*src_p;
	size_t	i;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (src == dst || !len)
		return (dst);
	if (src_p < dst_p)
	{
		while (++i <= len)
		{
			dst_p[len - i] = src_p[len - i];
		}
	}
	else
		while (len-- > 0)
			*dst_p++ = *src_p++;
	return (dst);
}

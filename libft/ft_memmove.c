/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:12:43 by ysalaun           #+#    #+#             */
/*   Updated: 2017/11/09 02:19:49 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*isrc;
	char	*idest;

	idest = (char *)dest;
	isrc = (char *)src;
	i = 0;
	if (src < dest)
	{
		i = n;
		while (i--)
			idest[i] = isrc[i];
	}
	while (i < n)
	{
		idest[i] = isrc[i];
		i++;
	}
	dest = idest;
	return (dest);
}

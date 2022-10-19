/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:54:32 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/14 11:24:35 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size && ((size_t) - 1 / size) < count)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

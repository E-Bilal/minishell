/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:25:48 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:25:31 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_data	ft_memset(t_data b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(t_bytes)(b + i) = (t_byte)c;
		i++;
	}
	return (b);
}

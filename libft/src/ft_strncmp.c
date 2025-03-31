/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:02:13 by senayat           #+#    #+#             */
/*   Updated: 2024/10/28 10:43:49 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const t_str s1, const t_str s2, size_t n)
{
	t_str	f;
	t_str	s;

	f = s1;
	s = s2;
	while (*f && *f == *s && n > 0)
	{
		f++;
		s++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(t_bytes)f - *(t_bytes)s);
}

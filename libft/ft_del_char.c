/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:29:46 by anel-bou          #+#    #+#             */
/*   Updated: 2019/07/23 10:49:06 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_del_char(char *s, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			s[j++] = s[i];
		i++;
	}
	s[j] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:04:23 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:04:24 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nelements(long num)
{
	int	c;

	c = 0;
	if (num == 0)
		c += 1;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		el;
	int		flag;
	char	*str;
	long	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	el = ft_nelements(num) + flag;
	str = (char *)malloc(el + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (flag > 0)
		str[0] = '-';
	str[el] = '\0';
	while (el-- > flag)
	{
		str[el] = ((num % 10) + '0');
		num = num / 10;
	}
	return (str);
}

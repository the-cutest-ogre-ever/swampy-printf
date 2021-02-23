/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_i_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static char	*set_num(char *str, unsigned int n, int length)
{
	str[length] = '\0';
	length--;
	while (n > 9)
	{
		str[length--] = (n % 10) + '0';
		n /= 10;
	}
	str[length--] = (n % 10) + '0';
	if (length == 0)
		str[0] = '-';
	return (str);
}

char		*ft_u_itoa(unsigned int n)
{
	char			*str;
	int				length;
	unsigned int	n_copy;

	length = 1;
	n_copy = n;
	while (n_copy > 9)
	{
		length++;
		n_copy /= 10;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	str = set_num(str, n, length);
	return (str);
}

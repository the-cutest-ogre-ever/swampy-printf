/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer_utilities.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		dec_num_length(int i)
{
	int length;

	length = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		length++;
	}
	return (length);
}

int		dex_num_length(unsigned int i)
{
	int length;

	length = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 16;
		length++;
	}
	return (length);
}

char	*dec_to_dex(unsigned int i, t_output_format *format)
{
	char	*dex;
	int		length;

	length = dex_num_length(i);
	dex = (char *)malloc(sizeof(char) * length + 1);
	if (!dex)
		return (NULL);
	dex[length] = '\0';
	if (i == 0)
	{
		dex[0] = '0';
		return (dex);
	}
	while (i != 0)
	{
		if ((i % 16) < 10)
			dex[length - 1] = i % 16 + 48;
		else if ((i % 16) >= 10 && format->type == 'X')
			dex[length - 1] = i % 16 + 55;
		else if ((i % 16) >= 10 && (format->type == 'x' || format->type == 'p'))
			dex[length - 1] = i % 16 + 87;
		i /= 16;
		length--;
	}
	return (dex);
}

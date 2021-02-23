/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:41:42 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 21:42:46 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static int	print_spaces(t_output_format *format)
{
	int i;
	int counter;

	counter = 0;
	i = format->width - 1;
	if (format->is_percent && format->zero_flag)
		while (i-- > 0)
			counter += ft_putchar('0');
	else
		while (i-- > 0)
			counter += ft_putchar(' ');
	return (counter);
}

int			print_char(char c, t_output_format *format)
{
	int counter;

	counter = 0;
	if (format->left_alignment)
	{
		counter += ft_putchar(c);
		counter += print_spaces(format);
	}
	else
	{
		counter += print_spaces(format);
		counter += ft_putchar(c);
	}
	return (counter);
}

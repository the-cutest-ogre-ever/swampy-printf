/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.с                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:41:42 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 21:42:46 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static int	print_spaces(char *s, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (format->width)
	{
		if (format->precision && format->precision < ft_strlen(s))
			i = format->width - format->precision;
		else
			i = format->width - ft_strlen(s);
		while (i-- > 0)
			if (format->zero_flag)
				counter += ft_putchar('0');
			else
				counter += ft_putchar(' ');
	}
	return (counter);
}

static int	print_str_with_precision(char *s, t_output_format *format)
{
	int i;
	int ind;
	int counter;

	counter = 0;
	ind = 0;
	if ((format->precision && format->precision < ft_strlen(s)) ||
	(format->zero_precision_case && !format->precision))
		i = format->precision;
	else
		i = ft_strlen(s);
	while (i-- > 0)
		counter += ft_putchar(s[ind++]);
	return (counter);
}

int			print_string(char *s, t_output_format *format)
{
	int counter;

	counter = 0;
	if (!s)
		s = "(null)";
	if (format->zero_precision_case && !format->precision)
		s = "";
	if (format->left_alignment)
	{
		counter += print_str_with_precision(s, format);
		counter += print_spaces(s, format);
	}
	else
	{
		counter += print_spaces(s, format);
		counter += print_str_with_precision(s, format);
	}
	return (counter);
}

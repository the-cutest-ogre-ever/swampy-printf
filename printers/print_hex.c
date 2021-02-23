/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static int	print_num_with_precision(char *dex, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (*dex == '0' && format->zero_precision_case && !format->precision)
		return (counter);
	if (format->precision > ft_strlen(dex))
	{
		i = format->precision - ft_strlen(dex);
		while (i--)
			counter += ft_putchar('0');
	}
	ft_putstr_fd(dex, 1);
	counter += ft_strlen(dex);
	return (counter);
}

static int	print_zeros_and_spaces(char *dex, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (format->width)
	{
		if (format->precision > ft_strlen(dex))
			i = format->width - format->precision;
		else
			i = format->width - ft_strlen(dex);
		if (*dex == '0' && format->zero_precision_case && !format->precision)
			i++;
		while (i-- > 0)
			if (format->zero_flag && !format->left_alignment &&
			!format->precision && !format->zero_precision_case)
				counter += ft_putchar('0');
			else
				counter += ft_putchar(' ');
	}
	return (counter);
}

int			print_hex(unsigned int num, t_output_format *format)
{
	int		counter;
	char	*dex;

	dex = dec_to_dex(num, format);
	if (!dex)
		return (0);
	counter = 0;
	if (format->precision)
		format->zero_flag = 0;
	if (format->left_alignment)
	{
		counter += print_num_with_precision(dex, format);
		counter += print_zeros_and_spaces(dex, format);
	}
	else
	{
		counter += print_zeros_and_spaces(dex, format);
		counter += print_num_with_precision(dex, format);
	}
	free(dex);
	return (counter);
}

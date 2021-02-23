/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static int	print_num_with_precision(char *u_i, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (*u_i == '0' && format->zero_precision_case && !format->precision)
		return (counter);
	if (format->precision > ft_strlen(u_i))
	{
		i = format->precision - ft_strlen(u_i);
		while (i--)
			counter += ft_putchar('0');
	}
	i = 0;
	while (u_i[i])
		counter += ft_putchar(u_i[i++]);
	return (counter);
}

static int	print_zeros_and_spaces(char *u_i, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (format->width)
	{
		if (format->precision > ft_strlen(u_i))
			i = format->width - format->precision;
		else
			i = format->width - ft_strlen(u_i);
		if (*u_i == '0' && format->zero_precision_case && !format->precision)
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

int			print_u_integer(unsigned int num, t_output_format *format)
{
	int		counter;
	char	*u_i;

	if (format->precision)
		format->zero_flag = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	u_i = ft_u_itoa(num);
	counter = 0;
	if (format->left_alignment)
	{
		counter += print_num_with_precision(u_i, format);
		counter += print_zeros_and_spaces(u_i, format);
	}
	else
	{
		counter += print_zeros_and_spaces(u_i, format);
		counter += print_num_with_precision(u_i, format);
	}
	free(u_i);
	return (counter);
}

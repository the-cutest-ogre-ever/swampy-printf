/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"
#include <stdio.h>

static int	check_negative_int_case(int *num)
{
	int counter;

	counter = 0;
	if (*num < 0)
	{
		if (*num == -2147483648)
		{
			counter += ft_putchar('2');
			*num = -147483648;
		}
		*num = *num * -1;
	}
	return (counter);
}

static int	print_num_with_precision(int num, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (num == 0 && format->zero_precision_case && !format->precision)
		return (counter);
	if (num < 0)
	{
		if (!(num < 0 && format->zero_flag && !format->zero_precision_case &&
		!format->precision && !format->left_alignment && ((dec_num_length(num)
		> format->precision && format->width > dec_num_length(num)) ||
		(dec_num_length(num) < format->precision && format->width >
		format->precision))))
			counter += ft_putchar('-');
	}
	if (format->precision > dec_num_length(num))
	{
		i = format->precision - dec_num_length(num);
		while (i--)
			counter += ft_putchar('0');
	}
	counter += check_negative_int_case(&num);
	ft_putnbr_fd(num, 1);
	counter += dec_num_length(num);
	return (counter);
}

static int	print_zeros_and_spaces(int num, t_output_format *format,
int neg_flag)
{
	int counter;
	int i;

	counter = 0;
	if (format->width)
	{
		if (neg_flag)
			counter += ft_putchar('-');
		if (format->precision > dec_num_length(num))
			i = format->width - format->precision;
		else
			i = format->width - dec_num_length(num);
		if (num < 0)
			i--;
		while (i-- > 0)
			if (format->zero_flag && !format->left_alignment &&
			!format->precision && !format->zero_precision_case)
				counter += ft_putchar('0');
			else
				counter += ft_putchar(' ');
	}
	return (counter);
}

static int	print_rest(int num, t_output_format *format, int neg_flag)
{
	int counter;

	counter = 0;
	if (num == 0 && format->zero_precision_case && !format->precision)
	{
		while (format->width-- > 0)
			counter += ft_putchar(' ');
		return (counter);
	}
	else
		counter += print_zeros_and_spaces(num, format, neg_flag);
	return (counter);
}

int			print_integer(int num, t_output_format *format)
{
	int counter;
	int neg_flag;

	if (format->precision)
		format->zero_flag = 0;
	counter = 0;
	neg_flag = 0;
	if (num < 0 && format->zero_flag && !format->precision &&
		!format->zero_precision_case && !format->left_alignment &&
		((dec_num_length(num) > format->precision && format->width >
		dec_num_length(num)) || (dec_num_length(num) < format->precision
		&& format->width > format->precision)))
		neg_flag = 1;
	if (format->left_alignment)
	{
		counter += print_num_with_precision(num, format);
		counter += print_rest(num, format, neg_flag);
	}
	else
	{
		counter += print_rest(num, format, neg_flag);
		counter += print_num_with_precision(num, format);
	}
	return (counter);
}

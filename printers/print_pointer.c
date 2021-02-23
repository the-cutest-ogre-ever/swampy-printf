/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

static int	print_pointer_val(char *pointer, t_output_format *format)
{
	int counter;
	int i;
	int ind;

	counter = 0;
	i = 0;
	counter += ft_putchar('0');
	counter += ft_putchar('x');
	if (format->precision > ft_strlen(pointer))
	{
		i = format->precision - ft_strlen(pointer);
		while (i-- > 0)
			counter += ft_putchar('0');
	}
	if (format->precision > ft_strlen(pointer))
		i = format->precision;
	else if (format->zero_precision_case && !format->precision)
		i = 0;
	else
		i = ft_strlen(pointer);
	ind = 0;
	while (i-- > 0 && pointer[ind])
		counter += ft_putchar(pointer[ind++]);
	return (counter);
}

static int	print_spaces(char *pointer, t_output_format *format)
{
	int counter;
	int i;

	counter = 0;
	if (format->width)
	{
		i = format->width - ft_strlen(pointer) - 2;
		if (*pointer == '0' && (format->zero_precision_case &&
								!format->precision))
			i++;
		while (i-- > 0)
			counter += ft_putchar(' ');
	}
	return (counter);
}

int			print_pointer(unsigned long p, t_output_format *format)
{
	int		counter;
	char	*pointer;

	pointer = pointer_to_dex(p, format);
	if (!pointer)
		return (0);
	counter = 0;
	if (format->left_alignment)
	{
		counter += print_pointer_val(pointer, format);
		counter += print_spaces(pointer, format);
	}
	else
	{
		counter += print_spaces(pointer, format);
		counter += print_pointer_val(pointer, format);
	}
	free(pointer);
	return (counter);
}

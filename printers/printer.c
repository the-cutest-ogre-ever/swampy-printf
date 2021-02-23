/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printer.h"

int		printer(t_output_format *format, va_list *args)
{
	int counter;

	counter = 0;
	if (format->type == 'd' || format->type == 'i')
		counter += print_integer(va_arg(*args, int), format);
	if (format->type == 'u')
		counter += print_u_integer(va_arg(*args, unsigned int), format);
	if (format->type == 'c')
		counter += print_char(va_arg(*args, unsigned int), format);
	if (format->type == '%')
		counter += print_char('%', format);
	if (format->type == 's')
		counter += print_string(va_arg(*args, char *), format);
	if (format->type == 'x' || format->type == 'X')
		counter += print_hex(va_arg(*args, unsigned int), format);
	if (format->type == 'p')
		counter += print_pointer(va_arg(*args, unsigned long), format);
	return (counter);
}

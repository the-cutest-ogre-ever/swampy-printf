/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	process_arg(const char *input, va_list *arg, int *i)
{
	int				counter;
	t_output_format *format;

	counter = 0;
	*i = *i + 1;
	format = init_format();
	format = parse_format(input, format, *i, arg);
	if (format)
	{
		if (format->type != 0)
		{
			counter += printer(format, arg);
			while (input[*i] != (char)format->type)
				*i = *i + 1;
			*i = *i + 1;
		}
		free(format);
	}
	return (counter);
}

int			ft_printf(const char *input, ...)
{
	va_list			arg;
	int				counter;
	int				i;

	counter = 0;
	i = 0;
	va_start(arg, input);
	while (input[i])
		if (input[i] == '%')
			counter += process_arg(input, &arg, &i);
		else
			counter += ft_putchar(input[i++]);
	va_end(arg);
	return (counter);
}

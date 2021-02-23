/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.с                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:41:42 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 21:42:46 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_handler.h"

static void		fix_format(t_output_format *format)
{
	if (format->left_alignment && format->zero_flag)
		format->zero_flag = 0;
	if (format->width < 0)
	{
		format->left_alignment = 1;
		format->width *= -1;
	}
	if (format->precision < 0)
	{
		format->precision = 0;
		format->zero_precision_case = 0;
	}
	if (format->type == '%')
		format->is_percent = 1;
}

t_output_format	*init_format(void)
{
	t_output_format *format;

	format = (t_output_format*)malloc(sizeof(t_output_format));
	if (!format)
		return (NULL);
	format->left_alignment = 0;
	format->zero_flag = 0;
	format->width = 0;
	format->precision = 0;
	format->zero_precision_case = 0;
	format->type = 0;
	format->is_percent = 0;
	return (format);
}

static int		parse_flags(const char *input, t_output_format *format, int i)
{
	while (input[i] == '-')
	{
		format->left_alignment = 1;
		i++;
		while (input[i] == '0')
		{
			format->zero_flag = 1;
			i++;
		}
	}
	while (input[i] == '0')
	{
		format->zero_flag = 1;
		i++;
		while (input[i] == '-')
		{
			format->left_alignment = 1;
			i++;
		}
	}
	return (i);
}

static int		parse_precision(const char *input, t_output_format *format,
int i, va_list *arg)
{
	if (input[i] == '.')
	{
		format->zero_precision_case = 1;
		i++;
		if (input[i] == '*')
		{
			format->precision = va_arg(*arg, int);
			i++;
		}
		if (ft_isdigit(input[i]))
		{
			format->precision = ft_atoi(input + i);
			while (ft_isdigit(input[i]))
				i++;
		}
	}
	return (i);
}

t_output_format	*parse_format(const char *input, t_output_format *format,
int i, va_list *arg)
{
	i = parse_flags(input, format, i);
	if (input[i] == '*')
	{
		format->width = va_arg(*arg, int);
		i++;
	}
	if (ft_isdigit(input[i]))
	{
		format->width = ft_atoi(input + i);
		while (ft_isdigit(input[i]))
			i++;
	}
	i = parse_precision(input, format, i, arg);
	if (input[i] == 'i' || input[i] == 'd' || input[i] == 'u' || input[i] == 'c'
	|| input[i] == 's' || input[i] == 'x' || input[i] == 'X' || input[i] ==
	'p' || input[i] == '%')
		format->type = input[i];
	fix_format(format);
	return (format);
}

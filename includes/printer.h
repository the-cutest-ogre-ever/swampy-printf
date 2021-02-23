/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "basic_includes.h"
# include "printer_utilities.h"

int		printer(t_output_format *format, va_list *arg);
int		print_integer(int num, t_output_format *format);
int		print_u_integer(unsigned int num, t_output_format *format);
int		print_hex(unsigned int num, t_output_format *format);
int		print_char(char c, t_output_format *format);
int		print_string(char *s, t_output_format *format);
int		print_pointer(unsigned long p, t_output_format *format);
char	*ft_u_itoa(unsigned int n);
int		get_hex_num_length(unsigned int num);

#endif

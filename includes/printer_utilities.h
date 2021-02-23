/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utilities.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:22:02 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 23:22:52 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_UTILITIES_H
# define PRINTER_UTILITIES_H

# include <unistd.h>
# include "basic_includes.h"

int		ft_putchar(char c);
int		dec_num_length(int i);
int		dex_num_length(unsigned int i);
int		pointer_length(unsigned long i);
char	*dec_to_dex(unsigned int i, t_output_format *format);
char	*pointer_to_dex(unsigned long i, t_output_format *format);
#endif

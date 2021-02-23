/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:21:01 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 12:12:51 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HANDLER_H
# define FORMAT_HANDLER_H

# include "basic_includes.h"

t_output_format *init_format(void);
t_output_format *parse_format(const char *input, t_output_format *format, int
i, va_list *arg);

#endif

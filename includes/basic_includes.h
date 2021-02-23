/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_includes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:41:42 by ijose             #+#    #+#             */
/*   Updated: 2021/02/07 21:42:46 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_INCLUDES_H
# define BASIC_INCLUDES_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_output_format
{
	int				left_alignment;
	int				zero_flag;
	int				width;
	int				zero_precision_case;
	int				precision;
	int				is_percent;
	unsigned int	type;
}				t_output_format;

#endif

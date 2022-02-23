/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:24:41 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 14:23:44 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int type;
	int width;
	int	minus;
	int zero;
	int dot;
	int star;
}				t_flags;

int				ft_putchar(int c);
int				ft_printf(const char *something, ...);
int				ft_check_width(int width, int minus, int has_zero);
int				ft_check_percent(t_flags flags);
int				ft_convert_char(char c, t_flags flags);
int				ft_check_type(int something, t_flags flags, va_list args);
int				ft_putprecision(char *str, int precision);
int				ft_convert_str(char *str, t_flags flags);
int				ft_convert_int(long int i, t_flags flags);
int				ft_convert_xtoa(unsigned int i, int min, t_flags flags);
int				ft_convert_u(unsigned int uns, t_flags flags);
int				ft_convert_ptr(unsigned long long base, t_flags flags);
int				ft_check_percent(t_flags flags);
int				ft_is_in_type_list(int something);
int				ft_is_in_flags_list(int something);
char			*ft_utoa(unsigned int n);
char			*ft_strtolower(char *str);
char			*ft_convert_base(unsigned long long n, int base);
t_flags			ft_flag_minus(t_flags flags);
t_flags			ft_flag_width(va_list args, t_flags flags);
t_flags			ft_flag_digit(char c, t_flags flags);
int				ft_flag_dot(const char *save, int start,
				t_flags *flags, va_list args);

#endif

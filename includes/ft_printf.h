/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:18:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/23 10:47:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/incs/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>

# define PRINTF_WC_MASK_0	0b000000000000001111111
# define PRINTF_WC_MASK_1	0b000000000000000111111
# define PRINTF_WC_MASK_2	0b000000000011111000000
# define PRINTF_WC_MASK_3	0b000000000111111000000
# define PRINTF_WC_MASK_4	0b000001111000000000000
# define PRINTF_WC_MASK_5	0b000111111000000000000
# define PRINTF_WC_MASK_6	0b111000000000000000000

typedef struct			s_options
{
	int					opt_minus;
	int					opt_plus;
	int					opt_space;
	int					opt_zero;
	int					opt_hashtag;
	int					field_width;
	int					precision;
	char				l_flags[3];
}						t_options;

typedef struct			s_infos
{
	va_list				*ap;
	int					index;
	int					buf_index;
	int					total_ret;
	int					precision_zero;
	int					is_unsigned;
	int					total_buf_size;
	char				*format;
	char				*buffer;
	char				tmp_str[128];
	t_options			*options;
}						t_infos;

typedef struct			s_dispatch
{
	char				character;
	int					(*ptr)(t_infos *infos);
}						t_dispatch;

int						ft_printf(const char *format, ...);
int						get_options(t_infos *infos);
int						launch_conv(t_infos *infos);
int						do_conv(t_infos *infos);
void					init_opt(t_options *options);

/*
** MISC
*/

uintmax_t				get_good_cast(t_infos *infos);
uintmax_t				get_good_ucast(t_infos *infos);
int						insert_field(t_infos *infos);
int						insert_wchar(t_infos *infos, wchar_t c);
int						ft_wstrlen(wchar_t *wstr);
int						ft_wcharlen(wchar_t c);
int						check_and_realloc(t_infos *infos, int len);
void					fpf_llota_base(uintmax_t nb, t_infos *infos, int base\
, int maj);

/*
** CONV
*/

int						conv_decimal(t_infos *infos);
int						insert_nb(uintmax_t nb, t_infos *infos, int base\
, int maj);
int						insert_char(char c, t_infos *infos);
int						insert_string(char *s, t_infos *infos);
int						insert_hashtag(t_infos *infos, int base, int maj\
, int nb);
int						insert_unicode_char(t_infos *infos, wchar_t c);
int						insert_unicode_str(t_infos *infos, wchar_t *str);
int						conv_unicode_character(t_infos *infos);
int						insert_flags(t_infos *infos, int base);
int						conv_octal_maj(t_infos *infos);
int						conv_character(t_infos *infos);
int						conv_octal_min(t_infos *infos);
int						conv_hexa_maj(t_infos *infos);
int						conv_hexa_min(t_infos *infos);
int						conv_binary_maj(t_infos *infos);
int						conv_binary_min(t_infos *infos);
int						conv_decimal_upper(t_infos *infos);
int						conv_pointer(t_infos *infos);
int						conv_strings(t_infos *infos);
int						conv_udecimal_upper(t_infos *infos);
int						conv_udecimal(t_infos *infos);
int						conv_unicode_str(t_infos *infos);

#endif

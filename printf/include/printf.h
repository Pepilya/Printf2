/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <ipepelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:03:35 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 17:12:10 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_spec
{
	int				flag_plus;
	int				flag_space;
	int				flag_minus;
	int				flag_grid;
	int				flag_zero;
	int				acc_zero;
	int				count;
	char			*hex;
	int				sign;
	int				width;
	int				ispoint;
	int				acc;
	int				mod;
	char			type;
	char			*text;
	unsigned long	bp_num;
	long double		ap_num;
	struct s_spec	*next;
	struct s_spec	*prev;
}					t_spec;
int					ft_printf(const char *f, ...);
t_spec				*checkstring(const char *f);
int					isspec(const char *f, size_t i);
int					valid(const char *s, t_spec *sp, int i, char *flags);
int					setaccuracy(t_spec *sp, const char *s, int i);
int					toint(const char *s, int start, int len);
int					wrongsymbols(char c);
void				setmod(t_spec *sp, const char *s, int i);
t_spec				*getspec(t_spec *sp);
void				init(t_spec *sp);
void				printchar(t_spec *sp, va_list argp);
void				printwidthchar(t_spec *sp);
void				getstring(t_spec *sp, va_list argp);
void				printwidthstring(t_spec *sp, int size);
char				*iszero();
void				printnum(t_spec *sp, va_list argp);
char				*changenumtype(t_spec *sp, long long int d);
void				printunsignednum(t_spec *sp, va_list argp, char c, int ch);
char				*changeunnumtype(t_spec *sp, unsigned long long int d);
void				upper(char *str);
void				printpointer(t_spec *sp, va_list argp);
void				counting(t_spec *sp, char c, int len);
int					isdecimal(t_spec *sp);
void				printwidth(t_spec *sp, char *toprint, int i, int len);
void				printaccuracy(t_spec *sp, char *toprint, int i, int len);
char				pissign(t_spec *sp);
void				choice(t_spec *sp, char *toprint, char c);
char				choice_2(t_spec *sp, char *toprint, char c);
char				choice_1(t_spec *sp, char *toprint, char c);
char				*check(char *string, t_spec *sp);
void				getdb(t_spec *sp, va_list argp, char c, long double num);
char				*dbtost(t_spec *sp, unsigned long *arr, size_t i, size_t j);
void				getpercent(t_spec *sp);
void				getrest(t_spec *sp);
void				mkdouble(t_spec *sp, unsigned long *arr);

#endif

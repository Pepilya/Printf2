/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <ipepelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:03:35 by ipepelia          #+#    #+#             */
/*   Updated: 2019/10/23 18:03:00 by ipepelia         ###   ########.fr       */
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
# include "libft/libft.h"

/*typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;*/

typedef struct          s_spec{
    char *flags;
    int  width;
    int  isPoint;
    int  acc;
    char *accFlag;
    int  mod;
    char type;
    char *text;
    int  isPercent;
	unsigned long bp_num;
	long double ap_num;
	int sign;
    struct s_spec *next;
    struct s_spec *prev;
}                       t_spec;

/* ft_printf */

void ft_printf(const char *f, ...);

/* ParsingString */

t_spec *checkString(const char *f, va_list arg);
t_spec *getSpec(t_spec *sp, va_list arg);
int isSpec(const char *f, int i);
void valid(const char *s, t_spec *sp);

/* CreateSpecifiers.c */

int setAccuracy(t_spec *sp, const char *s, int i);
int isUniq(char *flags, char c);
int toInt(char *s, int start, int len);
int wrongSymbols(char c);
void setMod(t_spec *sp, char *s, int i);

/* CreateListSpecifiers.c */
t_spec *getSpec(t_spec *sp, va_list arg);
void init(t_spec *sp, va_list arg);

/* PrintChar */
void getChar(t_spec *sp, va_list argp);
void printWidthChar(t_spec *sp);

/* PrintString */
void getString(t_spec *sp, va_list argp);
void printWidthString(t_spec *sp, char *s);

/* PRINT INTEGER */

/* PrintNumSigned.c */
void printNum(t_spec *sp, va_list argp);
char *changeNumType(t_spec *sp, long long int d);

/* PrintNumUnsigned.c */
void printUnsignedNum(t_spec *sp, va_list argp);
char *changeUnNumType(t_spec *sp, unsigned long long int d);
void toUpper(char *str);

/* PrintNumSpecifiers.c */
int isDecimal(t_spec *sp);
void cutLength(t_spec *sp);
void printWidth(t_spec *sp, char *toPrint);
void printAccuracy(t_spec *sp, char *toPrint);

/* PrintDouble.c */

void getDouble(t_spec *sp, va_list argp);


#endif

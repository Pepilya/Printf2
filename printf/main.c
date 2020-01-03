/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <ipepelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:18:26 by ipepelia          #+#    #+#             */
/*   Updated: 2019/11/20 17:32:32 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"
#include <stdio.h>


// ЧАСТЬ 4 - ВЫВОД ВЕЩЕСТВЕННЫХ ЗНАЧЕНИЙ



// ЧАСТЬ 3 - ВЫВОД ЦЕЛОЧИСЛЕННЫХ ЗНАЧЕНИЙ

void toUpper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper((char) str[i]);
		i++;
	}
}
// ОБработка значения модификаторы. Приведение типа (h hh l ll) пока работают только h и hh
char *changeIntType(t_spec *sp, int d)
{
	char *string;
	int base;

	base = 10;
	if (sp->type == 'X' || sp->type == 'x' || sp->type == 'p')
		base = 16;
	if (sp->type == 'o')
		base = 8;
	if (sp->mod == 0)
		string = ft_itoa_base(d, base);
	if (sp->mod == 1 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((char) d, base);
	else if (sp->mod == 1)
		string = ft_itoa_base((unsigned char) d, base);
	if (sp->mod == 2 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((short) d, base);
	else if (sp->mod == 2)
		string = ft_itoa_base((unsigned short) d, base);
	if (sp->mod == 3)
		string = ft_itoa_base((long long) d, base);
	if (sp->mod == 4)
		string = ft_itoa_base((long) d, base);
	if (sp->type == 'X')
		toUpper(string);
	return string;
}

// Обработка значения точность.
void printAccuracy(t_spec *sp, char *toPrint) {
	int i;
	int len;

	len = ft_strlen(toPrint);
	if (ft_strchr(sp->accFlag, '-')) {
		ft_putstr(toPrint);
		i = 0;
		while (++i < (sp->acc - len) + 1)
			ft_putchar(' ');
	}
	if (!ft_strchr(sp->accFlag, '-')) {
		i = 0;
		while (++i < (sp->acc - len) + 1) {
			if (ft_strchr(sp->accFlag, '+')) {
				ft_putchar(' ');
			} else
				ft_putchar('0');
		}
		ft_putstr(toPrint);
	}
}

void printWidth(t_spec *sp, char *toPrint) {
	int i;
	int len;

	len = ft_strlen(toPrint);
	if (ft_strchr(sp->flags, '-')) {
		ft_putstr(toPrint);
		i = 0;
		while (++i < (sp->width - len) + 1)
			ft_putchar(' ');
	} else {
		i = 0;
		while (++i < (sp->width - len) + 1) {
			if (ft_strchr(sp->flags, '0') && !sp->acc)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putstr(toPrint);
	}
}
void cutLength(t_spec *sp) {
	if (sp->acc > 0){
		if (ft_strchr(sp->accFlag, '-'))
			sp->acc -= 1;
	}
	else if (sp->width > 0 && sp->acc == 0)
		sp->width -= 1;
}
// определение разрядности
int isDecimal(t_spec *sp){
	if (sp->type == 'x' || sp->type == 'X' || sp->type == 'o' || sp->type == 'p')
	{
		if (ft_strchr(sp->flags, '#') || sp->type == 'p')
		{
			if (sp->type == 'x' || sp->type == 'X' || sp->type == 'p')
				ft_putstr("0x");
			if (sp->type == 'o')
				ft_putchar('0');
		}
		return 0;
	}
	else
		return 1;
}

// Печать целочисленных значений
void printNum(t_spec *sp, int d)
{
	char *toPrint;
	int check;

	ft_putstr(sp->text);
	toPrint = changeIntType(sp, d);
	check = isDecimal(sp);
	if (ft_strchr(sp->flags, '+') && check)
	{
		if (!ft_strchr(toPrint, '-'))
			ft_putchar('+');
		cutLength(sp);
	} else if (ft_strchr(sp->flags, ' ') && check)
	{
		if (!ft_strchr(toPrint, '-'))
			ft_putchar(' ');
		cutLength(sp);
	}
	if (sp->acc > 0 && sp->acc > sp->width)
		printAccuracy(sp, toPrint);
	else
		printWidth(sp, toPrint);
}

//  ЧАСТЬ 2 - ПЕЧАТЬ СТРОКИ И СИМВОЛА

void printChar(t_spec *sp, char c) {
	int i;
	int side;

	side = 0;
	if (ft_strchr(sp->flags, '-'))
		side = 1;
	ft_putstr(sp->text);
	if (side) {
		ft_putchar(c);
		i = 0;
		while (i < sp->width - 1) {
			ft_putchar(32);
			i++;
		}
	} else {
		i = 0;
		while (i < sp->width - 1) {
			ft_putchar(32);
			i++;
		}
		ft_putchar(c);
	}
}

void printString(t_spec *sp, char *s) {
	int i;
	int side;
	int size;

	size = ft_strlen(s);
	side = 0;
	if (ft_strchr(sp->flags, '-'))
		side = 1;
	ft_putstr(sp->text);
	if (side) {
		ft_putstr(s);
		i = 0;
		while (i < sp->width - size) {
			ft_putchar(32);
			i++;
		}
	} else {
		i = 0;
		while (i < sp->width - size) {
			ft_putchar(32);
			i++;
		}
		ft_putstr(s);
	}
}

//  ЧАСТЬ 1 - ОПРЕДЕЛЕНИЕ СПЕЦИФИКАТОРОВ
void init(t_spec *sp);

// установка модификаторов "h hh l ll L"
void setMod(t_spec *sp, char *s, int i) {
	if (s[i] == 'h' && s[i - 1] == 'h' && sp->mod == 2)
		sp->mod = 1;
	else if ((s[i] == 'h') || (s[i] == s[i - 1] && sp->mod == 1))
		sp->mod = 2;
	else if (s[i] == 'l' && s[i - 1] == 'l' && sp->mod == 4)
		sp->mod = 3;
	else if ((s[i] == 'l') || (s[i] == s[i - 1] && sp->mod == 3))
		sp->mod = 4;
	else if (s[i] == 'L')
		sp->mod = 5;
}

int toInt(char *s, int start, int len) {
	char *string;
	int number = 0;
	string = ft_strsub(s, start, len);
	number = ft_atoi(string);
	ft_strdel(&string);
	return number;
}

int isUniq(char *flags, char c) {
	int i;

	i = 0;
	while (flags[i]) {
		if (flags[i] == c)
			return 0;
		i++;
	}
	return 1;
}
// установка спецификатора точности
int setAccuracy(t_spec *sp, const char *s, int i) {
	int start;
	int accFlagInd;

	accFlagInd = 0;
	i++;
	while (s[i] && (s[i] == '0' || s[i] == '+' || s[i] == '-')) {
		if ((s[i] == '-' || s[i] == '+') && isUniq(sp->accFlag, s[i]) && accFlagInd < 2)
			sp->accFlag[accFlagInd] = s[i];
		accFlagInd++;
		i++;
	}
	if (s[i] >= '0' && s[i] <= '9') {
		start = i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		sp->acc = toInt(s, start, i - start);
	}
	return i;
}


// Заполняет данные спецификаторов. разобью на несколько функций как accuracy.
void valid(const char *s, t_spec *sp) {
	int i = 0;
	int start = 0;
	int flagIndex = 0;
	char *f = " +-#0";
	while (s[i]) {
		if (ft_strchr(f, s[i]) && isUniq(sp->flags, s[i]) && flagIndex < 5) {
			sp->flags[flagIndex] = s[i];
			flagIndex++;
		}
		if (s[i] > '0' && s[i] <= '9') {
			start = i;
			while ((s[i] >= '0' && s[i] <= '9') && s[i])
				i++;
			sp->width = toInt(s, start, i - start + 1);
			continue;
		}
		if (s[i] == '.') {
			i = setAccuracy(sp, s, i);
		}
		if (s[i] == 'L' || s[i] == 'h' || s[i] == 'l')
			setMod(sp, s, i);
		if (s[i])
			if (!s[i + 1])
				sp->type = s[i];
		i++;
	}
}
// чтобы избежать двойного процента %% (нужно доделать)
int isSpec(const char *f, int i) {
	if (i > 0) {
		if (f[i - 1] == '%' || f[i - 1] == '\\')
			return 0;
	}
	if (i < ft_strlen(f)) {
		if (f[i + 1] == '%' || f[i + 1] == '\\')
			return 0;
	}
	return 1;
}

t_spec *getSpec(t_spec *sp) {
	t_spec *tmp = NULL;
	if (sp == NULL) {
		sp = (t_spec *) malloc(sizeof(t_spec));
		init(sp);
		return sp;
	}
	while (sp->next != NULL)
		sp = sp->next;
	sp->next = (t_spec *) malloc(sizeof(t_spec));
	init(sp->next);
	tmp = sp;
	sp = sp->next;
	sp->prev = tmp;
	return sp;
}

int wrongSymbols(char c){
	char *rightSymbols = "cspdiouxXf";
	char *wrongSymbols = "!$&()/<=>?@[]^|{}`~\\";
	if ((ft_isalpha(c) || ft_strchr(wrongSymbols, c)) && !ft_strchr(rightSymbols, c))
		return 1;
	return 0;
}
// Очень костыльно, надо оптимизировать. Читаем строку f.
t_spec *checkString(const char *f) {
	char *dup = NULL;
	int i = 0;
	int j = 0;
	int startText = 0;
	int isWrong = 0;
	char *spec = "cspdiouxXf"; //спецификаторы типа
	t_spec *sp = NULL;
	while (f[i]) {
		if (f[i] == '%' && isSpec(f, i)) {
			j = i;
			sp = getSpec(sp); // получаем элемент списка
			sp->text = ft_strsub(f, startText, i - startText); // текст до спецификатора первой переменной (%s)
			while (!ft_strchr(spec, f[i]) && f[i]){
				if (wrongSymbols(f[i]))
				{
					isWrong = 1;
					break;
				}
				i++;
			}
			if (isWrong)
				continue;
			if (!f[i])
				break;
			startText = i + 1;
			dup = ft_strsub(f, j + 1, i - j);
		}
		i++;
		if (dup != NULL) {
			valid(dup, sp);
			ft_strdel(&dup);
		}
	}
	sp = getSpec(sp);
	sp->text = ft_strsub(f, startText, i - startText);
	return sp;
}
// Инициализация данных структуры (связанного списка)
void init(t_spec *sp) {
	sp->flags = (char *) malloc(sizeof(char) * 6); // строка для флагов +-0# и space
	ft_bzero(sp->flags, ft_strlen(sp->flags));
	sp->width = 0; // ширина
	sp->accFlag = (char *) malloc(sizeof(char) * 3); // отдельно флаги для точности, +- после точки, работают не так как обычные.
	ft_bzero(sp->accFlag, ft_strlen(sp->accFlag));
	sp->acc = 0; // точность.
	sp->mod = 0; // модификаторы, пока работают только hh и h.
	sp->type = 0; // тип
	sp->text = NULL; // это для текста перед переменной (%s).
	sp->next = NULL; // след узел
	sp->prev = NULL; // предыдущий узел
}

/*Начало функции. Сначала читаем строку f полностью и записываем все спецификаторы в связ. список (t_spec *sp)
 * - флаги, ширина, точность, тип и т.д. Далее на идем по списку и печатаем наши переменные (пока есть все типы, кроме float - самая сложная)
 * есть небольшие ошибки на типах p, x, o, исправлю. Не реализовал нормально %%, исправлю. Еще много костыльного кода, но пока работает и норм =))
	*/
void ft_printf(const char *f, ...) {
	char *string;
	char c;
	int d;
	va_list argp;
	va_start(argp, f);
	t_spec *sp = checkString(f); // читаем строку и записываем в список.
	while (sp->prev != NULL)
		sp = sp->prev;
	while (sp->next != NULL) {

		if (sp->type == 's') {
			string = va_arg(argp, char *);
			printString(sp, string);
		}
		if (sp->type == 'c') {
			c = va_arg(argp, char);
			printChar(sp, c);
		}
		if (sp->type == 'd' || sp->type == 'i' || sp->type == 'x'
		|| sp->type == 'X' || sp->type == 'o' || sp->type == 'u' || sp->type == 'p'){
			d = va_arg(argp, int);
			printNum(sp, d);
		}
		// ... добавть остальные типы!
		sp = sp->next;
	}
	ft_putstr(sp->text);
	va_end(argp);
}

int main() {
	char x = 10;
	char *s = "HI I am here";
	printf("%s %d\n", s, x);
	ft_printf("%s %d\n", s, x);
	return 0;
}

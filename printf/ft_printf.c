#include "printf.h"
#include <stdarg.h>

/*Начало функции. Сначала читаем строку f полностью и записываем все спецификаторы в связ. список (t_spec *sp)
 * - флаги, ширина, точность, тип и т.д. Далее на идем по списку и печатаем наши переменные (пока есть все типы, кроме float - самая сложная)
 * есть небольшие ошибки на типах p, x, o, исправлю. Не реализовал нормально %%, исправлю. Еще много костыльного кода, но пока работает и норм =))
	*/
void ft_printf(const char *f, ...)
{
	char *string;
	char c;
	long long d;
	unsigned long long int l;
	long double fl;

	va_list argp;
	va_start(argp, f);
	t_spec *sp = checkString(f); // читаем строку и записываем в список.
	while (sp->prev != NULL)
		sp = sp->prev;
	while (sp->next != NULL)
	{
		if (sp->type == 's')
		{
			string = va_arg(argp, char *);
			printString(sp, string);
		}
		if (sp->type == 'c')
		{
			c = va_arg(argp, int);
			printChar(sp, c);
		}
		if (sp->type == 'd' || sp->type == 'i' || sp->type == 'p')
		{
			d = va_arg(argp, long long int);
			printNum(sp, d);
		}
		if (sp->type == 'X' || sp->type == 'o' || sp->type == 'u' || sp->type == 'x')
		{
			l = va_arg(argp, unsigned long long int);
			printUnsignedNum(sp, l);
		}
		if (sp->type == 'f')
		{
			if (sp->mod == 5)
				fl = va_arg(argp, long double);
			else
				fl = (long double)va_arg(argp, double);
			getDouble(sp, fl);
		}
		sp = sp->next;
	}
	ft_putstr(sp->text);
	va_end(argp);
}
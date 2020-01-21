#include "printf.h"
#include <stdarg.h>

/*Начало функции. Сначала читаем строку f полностью и записываем все спецификаторы в связ. список (t_spec *sp)
 * - флаги, ширина, точность, тип и т.д. Далее на идем по списку и печатаем наши переменные (пока есть все типы, кроме float - самая сложная)
 * есть небольшие ошибки на типах p, x, o, исправлю. Не реализовал нормально %%, исправлю. Еще много костыльного кода, но пока работает и норм =))
	*/

void ft_printf(const char *f, ...)
{
	t_spec *sp;
	va_list argp;

	va_start(argp, f);
	sp = checkString(f, argp); // читаем строку и записываем в список.
	while (sp->prev != NULL)
		sp = sp->prev;
	while (sp->next != NULL)
	{
		if (sp->type == 's')
			getString(sp, argp);
		else if (sp->type == 'c')
			getChar(sp, argp);
		else if (sp->type == 'd' || sp->type == 'i' || sp->type == 'p')
			printNum(sp, argp);
		else if (sp->type == 'X' || sp->type == 'o' || sp->type == 'u' || sp->type == 'x')
			printUnsignedNum(sp, argp);
		else if (sp->type == 'f')
			getDouble(sp, argp);
		sp = sp->next;
	}
	ft_putstr(sp->text);
	va_end(argp);
}
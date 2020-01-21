#include "printf.h"

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
	} else{
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
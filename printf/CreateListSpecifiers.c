#include "printf.h"

// Инициализация данных структуры (связанного списка)
void init(t_spec *sp)
{
	sp->flags = (char *) malloc(sizeof(char) * 6); // строка для флагов +-0# и space
	ft_bzero(sp->flags, ft_strlen(sp->flags));
	sp->width = 0; // ширина
	sp->accFlag = (char *) malloc(sizeof(char) * 3); // отдельно флаги для точности, +- после точки, работают не так как обычные.
	ft_bzero(sp->accFlag, ft_strlen(sp->accFlag));
	sp->isPoint = 0;
	sp->acc = 0; // точность.
	sp->mod = 0; // модификаторы, пока работают только hh и h.
	sp->type = 0; // тип
	sp->bp_num = 0;
	sp->ap_num = 0;
	sp->isPercent = 0;
	sp->text = NULL; // это для текста перед переменной (%s).
	sp->next = NULL; // след узел
	sp->prev = NULL; // предыдущий узел
}

// Создание структуры - связанного списка.
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
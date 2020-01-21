# include "printf.h"

void valid(const char *s, t_spec *sp)
{
	int i = 0;
	int start = 0;
	int flagIndex = 0;
	char *f = " +-#0";
	while (s[i]) {
		if (ft_strchr(f, s[i]) && isUniq(sp->flags, s[i]) && flagIndex < 5)
		{
			sp->flags[flagIndex] = s[i];
			flagIndex++;
		}
		if (s[i] > '0' && s[i] <= '9')
		{
			start = i;
			while ((s[i] >= '0' && s[i] <= '9') && s[i])
				i++;
			sp->width = toInt(s, start, i - start + 1);
			continue;
		}
		if (s[i] == '.')
			i = setAccuracy(sp, s, i);
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

t_spec *checkString(const char *f, va_list arg) {
	char *dup = NULL;
	int i = 0;
	int j = 0;
	int startText = 0;
	char *spec = "cspdiouxXf"; //спецификаторы типа
	t_spec *sp = NULL;
	while (f[i]) {
		if (f[i] == '%' && isSpec(f, i)) {
			j = i;
			sp = getSpec(sp, arg); // получаем элемент списка
			sp->text = ft_strsub_mod(f, startText, i - startText - 1, '%');// текст до спецификатора первой переменной (%s)
			while (!ft_strchr(spec, f[i]) && f[i] && !wrongSymbols(f[i]))
				i++;
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
	sp = getSpec(sp, arg);
	sp->text = ft_strsub_mod(f, startText, i - startText - 1, '%');
	return sp;
}
#include "printf.h"


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

int wrongSymbols(char c){
	char *rightSymbols = "cspdiouxXfhlL";
	char *wrongSymbols = "!$&()/<=>?@[]^|{}`~\\";
	if ((ft_isalpha(c) || ft_strchr(wrongSymbols, c)) && !ft_strchr(rightSymbols, c))
		return 1;
	return 0;
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

int setAccuracy(t_spec *sp, const char *s, int i) {
	int start;
	int accFlagInd;

	sp->isPoint = 1;
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
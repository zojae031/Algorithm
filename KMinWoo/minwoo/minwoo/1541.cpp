#include <stdio.h>
#include <stdlib.h>

int len(char* str) {
	int i;
	for (i = 0;; i++) {
		if (str[i] == '\0') return i;
	}
}

int number(char* str, int* c) {
	int i;
	int num = 0;
	for (i = 0;; i++) {
		if (str[i] <= '9' && '0' <= str[i])
			num = num * 10 + (str[i] - '0');
		else {
			(*c) = (*c) + i - 1;
			return num;
		}
	}
}

int main() {

	char str[53];
	int ans = 0, n;
	int l, i;
	int flag = 0;
	scanf("%s", str);
	l = len(str);

	for (i = 0; i < l; i++) {

		if (str[i] == '-') {
			flag = 1;
		}
		else if (str[i] <= '9' && '0' <= str[i]) {
			n = number(&str[i], &i);
			if (flag == 1) ans -= n;
			else ans += n;
		}
	}

	printf("%d", ans);
	return 0;
}
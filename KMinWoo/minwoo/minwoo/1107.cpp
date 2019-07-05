#include <stdio.h>
#include <iostream>

inline int min(int a, int b) { return a > b ? b : a; }
bool flag[10] = { true, true, true, true, true, true, true, true, true, true, };
char str[10];
int w = 0, f, i = 0, _c;
int num = 0, n;
int ans;

int sol(int make, int size, int ans, int limit) {
	int i, j;
	int t = 1, div = 0;

	if (size == limit) {
		for (i = 0; i < size - 1; i++) t *= 10;
		for (; t != 1; t /= 10) {
			if (make / t == 0) div++;
			else break;
		}
		ans = min(ans, (make > w ? make - w : w - make) + size - div);
	}
	else {
		for (i = 0; i < size - 1; i++) t *= 10;
		div = 0;
		for (j = t; j != 1; j /= 10) {
			if (make / j == 0) div++;
			else break;
		}
		ans = min(ans, (make > w ? make - w : w - make) + size - div);
		for (int i = 0; i < 10; i++) {
			if (flag[i]) ans = sol((make * 10) + i, size + 1, ans, limit);
		}
	}
	return ans;
}

int main() {


	scanf("%s", str);
	scanf("%d", &f);

	while (str[i] != '\0') {
		w = (w * 10) + (str[i++] - '0');
	}
	n = i;
	for (i = 0; i < f; i++) {
		scanf("%d", &_c);
		flag[_c] = false;
	}
	ans = w > 100 ? w - 100 : 100 - w;

	for (i = 0; i < 10; i++) {
		if (flag[i]) ans = min(ans, sol(i, 1, ans, 6));
	}
	printf("%d", ans);




	return 0;
}
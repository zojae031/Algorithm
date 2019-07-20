#include <stdio.h>

int s[7][300001];
int top[7] = { 0,0,0,0,0,0,0 };

int main() {

	int n, p, pos, t;
	int ans = 0;
	int i, j;

	scanf("%d %d", &n, &p);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &pos, &t);
		for (j = top[pos] - 1; j >= 0 && s[pos][j] > t; j--)
			ans++;
		top[pos] = j + 1;
		if (s[pos][top[pos] - 1] != t) {
			s[pos][top[pos]++] = t;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
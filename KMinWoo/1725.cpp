#include <stdio.h>
#include <stdlib.h>

inline int max(int a, int b) { return a > b ? a : b; }

int s[100001];
int info[100001];

int main() {

	int n, top = 0, i, f;
	int ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &info[i]);

	s[top++] = 0;
	for (i = 1; i < n; i++) {
		if (info[i] >= info[s[top - 1]]) s[top++] = i;
		else {
			while (top > 0 && info[i] < info[s[top - 1]]) {
				top--;
				ans = max(ans, (i - (top - 1 < 0 ? s[top - 1] - 1 : s[top - 1]) - 1)*info[s[top]]);
			}
			s[top++] = i;
		}
	}
	while (top > 0) {
		top--;
		ans = max(ans, (i - (top - 1 < 0 ? s[top - 1] - 1 : s[top - 1]) - 1)*info[s[top]]);
	}
	ans = max(ans, n * info[s[0]]);
	printf("%d", ans);

	return 0;
}
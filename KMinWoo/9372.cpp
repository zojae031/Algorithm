#include <stdio.h>

int main() {
	int t, n, m, s, e;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &s, &e);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}
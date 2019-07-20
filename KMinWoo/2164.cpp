#include <stdio.h>

int num[500001];

int main() {
	int n, e;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		num[i] = i;
	}
	while (n != 1) {

		j = i = 1;
		e = n;
		if (n % 2 != 0) {
			e = n - 1;
			j++;
			num[i] = num[n];
		}

		for (; i <= e / 2; i++) {
			num[j++] = num[i << 1];
		}
		n = i - (n % 2 == 0 ? 1 : 0);
	}


	printf("%d", num[1]);
	return 0;
}
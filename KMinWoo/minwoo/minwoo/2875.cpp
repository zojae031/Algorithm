#include <stdio.h>

int main() {
	int n, m, k;
	int num = 0;
	int d;
	scanf("%d %d %d", &n, &m, &k);
	
	if (n != (m << 1)) {
		k = k - (n > (m << 1) ? n - (m << 1) : m - (n >> 1) + (n % 2));
		if (n > (m << 1))
			n = m << 1;
		else {
			n = (n % 2 == 0 ? n : n - 1);
			m = n >> 1;
		}
	}
	if (k > 0) {
		d = k % 3 == 0 ? k / 3 : k / 3 + 1;
		m = m - d;
	}
	printf("%d",m);


	return 0;
}
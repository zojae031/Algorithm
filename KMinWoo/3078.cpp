#include <stdio.h>

int info[300001];

int main() {

	int n, k, j, i;
	long long ans = 0;
	char name[21];
	int m[21] = { 0, };

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s", name);
		for (j = 0; name[j] != '\0'; j++);
		m[j]++;
		info[i] = j;
		if (m[info[i]] > 1)
			ans += (m[info[i]] - 1);
		if (i >= k)
			m[info[i - k]]--;
	}
	printf("%lld", ans);
	return 0;
}
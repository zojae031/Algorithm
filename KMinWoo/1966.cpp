#include <stdio.h>

int info[101];

int main() {
	int t, i, ans, c;
	int n, m, flag, l;
	int level[10];
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= 9; i++)level[i] = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &info[i]);
			level[info[i]]++;
		}
		for (i = info[m] + 1, ans = 0; i <= 9; i++)
			ans += level[i];
		if (level[info[m]] == 1) ans++;
		else {
			for (i = m + 1, c = 0, flag = 0; i < n; i++) {
				if (flag) {
					if (info[i] == info[m]) c++;
					else if (info[i] < l) {
						c = 0;
						l = info[i];
					}
				}
				else {
					if (info[i] > info[m]) {
						l = info[i];
						flag = 1;
						c = 0;
					}
					else if (info[i] == info[m]) c++;
				}
			}
			ans += (flag == 0 ? level[info[m]] - c : c + 1);
		}
		printf("%d\n", ans);
	}

	return 0;
}
#include <stdio.h>

char command[100001];
int info[100001];


int main() {

	int t, n, i, j;
	int s, e, v, temp;

	scanf("%d", &t);

	while (t--) {
		scanf("%s", command);
		scanf("%d", &n);
		getchar();
		getchar();
		scanf("%d", &info[0]);
		for (i = 1; i < n; i++)
			scanf(",%d", &info[i]);
		getchar();
		s = 0;
		e = n - 1;
		v = 0;
		for (i = 0; command[i] != '\0'; i++) {
			if (command[i] == 'R') {
				v = v == 0 ? 1 : 0;
				temp = s;
				s = e;
				e = temp;
			}
			else if ((v == 0 ? e - s : s - e) != -1) {
				if (v == 1) s--;
				else s++;
			}
			else {
				printf("error\n");
				break;
			}
		}
		if (command[i] == '\0') {
			printf("[");
			if ((v == 0 ? e - s : s - e) != -1)
				printf("%d", info[s]);
			if (v == 0) {
				for (i = s + 1; i <= e; i++)
					printf(",%d", info[i]);
			}
			else {
				for (i = s - 1; i >= e; i--)
					printf(",%d", info[i]);
			}
			printf("]\n");
		}
	}

	return 0;
}
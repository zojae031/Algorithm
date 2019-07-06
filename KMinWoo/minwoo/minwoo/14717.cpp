#include <stdio.h>

int main() {

	int num_1, num_2;
	int pair[20];
	int _ca[20];
	int c, ans;
	scanf("%d %d", &num_1, &num_2);
	for (int i = 0; i < 20; i++) {
		pair[i] = (i % 10) + 1;
		_ca[i] = 0;
	}
	ans = 0;
	pair[num_1 - 1] = 0;
	pair[(num_2==num_1) ? (num_2 + 9) : num_2 - 1] = 0;
	c = num_1 == num_2 ? num_1 + 9 : (num_1 + num_2) % 10;

	for (int i = 0; i < 19; i++) {
		if (pair[i] != 0) {
			for (int j = i + 1; j < 20; j++) {
				if (pair[j] != 0) {
					if (pair[i] == pair[j])
						_ca[pair[i] + 9]++;
					else
						_ca[(pair[i] + pair[j])%10]++;
				}
			}
		}
	}

	for (int i = 0; i < c; i++) {
		ans += _ca[i];
	}

	printf("%.3lf", ans / 153.0);

	return 0;
}
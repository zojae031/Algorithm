#include <stdio.h>

inline int max_size(int a, int b) { return a > b ? a : b; }
int map[50][50];
int x, y, i, j;

int square(int now_x, int now_y, int value) {
	int ref = 1;
	int next_x = now_x + 1, next_y = now_y + 1;
	
	while (next_x < x && next_y < y) {
		if (value == map[now_y][next_x] && value == map[next_y][now_x] && value == map[next_y][next_x]) 
			ref = next_x - now_x + 1;

		next_x++;
		next_y++;
	}
	
	return ref * ref;
}

int main() {

	int ans = 0;
	char str[51];
	scanf("%d %d", &y, &x);
	for (i = 0; i < y; i++) {
		scanf("%s", str);
		for (j = 0; j < x; j++) 
			map[i][j] = str[j] - '0';
	}
	for (i = 0; i < y; i++) 
		for (j = 0; j < x; j++) 
			ans = max_size(square(j, i, map[i][j]), ans);
		
	printf("%d",ans);
	return 0;
}
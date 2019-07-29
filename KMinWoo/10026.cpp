#include <stdio.h>
#include <queue>

using namespace std;

char map[101][101];
bool visit[101][101] = { false, };
queue<pair<int, int>> q;
int _ca[2][4] = { {0,0,1,-1}, {1,-1,0,0} };
int n;

void bfs(int x, int y, int flag) {
	int size, i;
	char color = map[y][x];
	pair<int, int> now;


	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 0; i < 4; i++) {
			x = now.first + _ca[0][i];
			y = now.second + _ca[1][i];
			if ((x >= 0) && (x < n) && (y >= 0) && (y < n)) {
				if (map[y][x] == color && visit[y][x] == false) {
					visit[y][x] = true;
					q.push({ x,y });
				}// 일반적인 경우에는 기존의 색상과 같은 경우에만 해당 구역에서 다시 탐색을 수행한다.
				if (flag == 1 && (color == 'R' || color == 'G')) {
					if ((map[y][x] == 'R' || map[y][x] == 'G') && visit[y][x] == false) {
						visit[y][x] = true;
						q.push({ x,y });
					}
				}// 색맹의 경우에는 R,G의 구분을 명확히 하지 못하므로 R,G인경우에는 두색상모드 다시 탐색을 수행한다.
			}
		}
	}
}

int main() {
	int i, j, ans, ans2;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				bfs(j, i, 0);
				ans++;
			}
		}
	}// 일반적인 경우

	ans2 = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				bfs(j, i, 1);
				ans2++;
			}
		}
	}// 색맹의 경우
	printf("%d %d", ans, ans2);
	return 0;
}
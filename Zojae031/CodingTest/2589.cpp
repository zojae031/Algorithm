#pragma warning(disable:4996)
#include<iostream>
#include <queue>
using namespace std;

int width, height;
char map[51][51] = { "" };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
queue<pair<int, int>> q;

int bfs(int x, int y) {
	bool check[51][51] = { false };
	int cnt = 0;
	check[x][y] = true;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x_pos = q.front().first;
			int y_pos = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int x_vector = x_pos + dx[j];
				int y_vector = y_pos + dy[j];
				if (x_vector >= 0 && x_vector < width && y_vector >= 0 && y_vector < height) {
					if (map[x_vector][y_vector] == 'L' && check[x_vector][y_vector] == false) {
						q.push(make_pair(x_vector, y_vector));
						check[x_vector][y_vector] = true;
					}
				}
			}

		}
		cnt++;
	}
	return cnt - 1;
}
int main() {

	int max = 0;
	char ch;
	scanf("%d %d", &width, &height);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cin >> ch;
			map[i][j] = ch;
		}
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == 'L') {
				q.push(make_pair(i, j));
				max = std::max(max, bfs(i, j));
			}
		}
	}
	printf("%d", max);
	return 0;
}
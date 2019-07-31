#include<iostream>
#include<queue>
using namespace std;

//º¸¹°¼¶
//bfs,dfs
//

int w;
int h;
int map[51][51];
bool check[51][51] = { false };
queue <pair<int, int>> q;

int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
void bfs(int x, int y) {

	q.push(make_pair(x, y));
	check[x][y] = true;
	while (!q.empty())
	{

		int size = q.size();
		for (int j = 0; j < size; j++) {
			int pos_x = q.front().first;
			int pos_y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				if (0 <= pos_x + dx[i] && pos_x + dx[i] < w && 0 <= pos_y + dy[i] && pos_y + dy[i] < h) {
					if (map[pos_x + dx[i]][pos_y + dy[i]] == 1 && check[pos_x + dx[i]][pos_y + dy[i]] == false) {
						check[pos_x + dx[i]][pos_y + dy[i]] = true;
						q.push(make_pair(pos_x + dx[i], pos_y + dy[i]));
					}
				}
			}
		}
	}

}

int main()
{
	int a;
	int cnt = 0;
	while (1) {

		cnt = 0;
		cin >> h >> w;
		if (w == 0 && h == 0) {
			break;
		}

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> a;
				map[i][j] = a;
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				check[i][j] = false;
			}
		}
		cnt = 0;
	}
}
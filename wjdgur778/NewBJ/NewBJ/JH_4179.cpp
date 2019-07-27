#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//불!
//불이 확산하고 이동
//체크되어있으면 못가고 r-1혹은 c-1까지 도달할수 있으면 탈출 가능 못하면 불가능
//큐

int r;
int c;
char map[1001][1001];
int check[1001][1001] = { 0 };
queue <pair <int, int>> q;
queue <pair <int, int>> f_q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans;
int cnt = 1;
bool flag = true;

void bfs() {
	int x;
	int y;
	int f_x;
	int f_y;
	int cnt = 1;

	if (q.front().first == 0 || q.front().first == r - 1 || q.front().second == 0 || q.front().second == c - 1) {
		ans = 1;
		return;
	}//J가 가장자리에 있을때는 무조건 답 1
	 //현재 포지션 의 다음 것을 비교하기때문에 예외처리를 해줌 


	while (!q.empty()) {
		int q_size = q.size();
		int f_size = f_q.size();

		for (int k = 0; k < f_size; k++) {
			f_x = f_q.front().first;
			f_y = f_q.front().second;
			f_q.pop();

			for (int i = 0; i < 4; i++) {

				if (0 <= f_x + dx[i] && f_x + dx[i] < r && 0 <= f_y + dy[i] && f_y + dy[i] < c)
				{
					if (map[f_x + dx[i]][f_y + dy[i]] == '.' || map[f_x + dx[i]][f_y + dy[i]] == 'J') {
						map[f_x + dx[i]][f_y + dy[i]] = 'F';
						f_q.push(make_pair(f_x + dx[i], f_y + dy[i]));
					}
				}
			}
		}//불의 움직임

		for (int k = 0; k < q_size; k++) {
			
			x = q.front().first;
			y = q.front().second;//지훈이

			q.pop();

			for (int i = 0; i < 4; i++) {

				if (0 <= x + dx[i] && x + dx[i] < r && 0 <= y + dy[i] && y + dy[i] < c)
				{

					if (check[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] != 'F') {
						check[x + dx[i]][y + dy[i]] = 1;
						q.push(make_pair(x + dx[i], y + dy[i]));
						if (x + dx[i] == 0 || x + dx[i] == r - 1 || y + dy[i] == 0 || y + dy[i] == c - 1) {
							ans = ++cnt;
							flag = true;
							return;
						}
						else
							flag = false;
					}
				}

			}//지훈이의 움직임

		}
		cnt++;//큐의 깊이
	}//불이 먼저 움직이고 그 다음에 지훈이를 움직인다.

}
int main() {
	string a;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> a;
		for (int k = 0; k < c; k++) {
			map[i][k] = a[k];
			if (map[i][k] == 'J') {
				check[i][k] = 1;
				q.push(make_pair(i, k));
			}
			else if (map[i][k] == '#') {
				check[i][k] = 1;
			}
			if (map[i][k] == 'F') {
				check[i][k] = 2;
				f_q.push(make_pair(i, k));
			}
		}
	}
	bfs();
	if (flag == false)cout << "IMPOSSIBLE";
	else if (ans == 0) cout << "IMPOSSIBLE";
	else cout << ans;
	return 0;
}

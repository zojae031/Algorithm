#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
//보물섬
//bfs

int w;
int l;
char map[51][51];
bool check[51][51] = { false };
queue <pair<int, int>> q;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int cnt=0;
int ans=0;

int bfs(int x, int y) {


	check[x][y] = true;
	while (!q.empty()) {

		int real_x;
		int real_y;
		int size= q.size();//

		for (int i = 0; i < size; i++) {
			real_x = q.front().first;
			real_y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				if (0 <= real_x + dx[j] && real_x + dx[j] < w && 0 <= real_y + dy[j] && real_y + dy[j] < l) {
					if (map[real_x + dx[j]][real_y + dy[j]] == 'L'&&check[real_x + dx[j]][real_y + dy[j]] == false) {
						q.push(make_pair(real_x + dx[j], real_y + dy[j]));
						check[real_x + dx[j]][real_y + dy[j]] = true;
					}

				}
			}//우,하,좌,상 순서로 탐색
		}
		cnt++;//bfs의 레벨 구하기
	}
	return cnt-1;
}
int main() {
	cin >> w >> l;
	string a;
	for (int i = 0; i < w; i++) {
		cin >> a;
		for (int j = 0; j < l; j++) {
			map[i][j] = a[j];
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < l; j++) {
			if (map[i][j] == 'L') {
				
				q.push(make_pair(i, j));
				check[i][j] = true;
				ans=max(ans,bfs(i, j));
				cnt = 0;
			
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < l; j++) {
						check[i][j] = false;
					}
				}
			}//'L'을 만날때마다 bfs를 돌려 가장 긴 거리를 구한다.
			 //이때 돌릴때마다 check는 초기화
		}
	}
	cout << ans;
	return 0;
}
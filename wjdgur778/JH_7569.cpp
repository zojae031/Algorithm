#include<iostream>
#include<queue>
#include <vector>
using namespace std;
//토마토
//bfs
//3차원,,
//입력순서 중요

int m;
int n;
int h;

int tomato[101][101][101];
bool check[101][101][101] = { {{false}} };
queue<vector<int>> q;
vector<int> a;
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,1,0,-1,0,0 };
int dz[] = { 1,0,-1,0,0,0 };

int cnt = 0;
void bfs() {

	while (!q.empty())
	{
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int pos_x = q.front()[0];
			int pos_y = q.front()[1];
			int pos_z = q.front()[2];
			q.pop();
			for (int i = 0; i < 6; i++) {
				if (0 <= pos_x + dx[i] && pos_x + dx[i] < h && 0 <= pos_y + dy[i] && pos_y + dy[i] < m && 0 <= pos_z + dz[i] && pos_z + dz[i] < n) {
					if (tomato[pos_x + dx[i]][pos_y + dy[i]][pos_z + dz[i]] != -1 && check[pos_x + dx[i]][pos_y + dy[i]][pos_z + dz[i]] == false) {

						check[pos_x + dx[i]][pos_y + dy[i]][pos_z + dz[i]] = true;
						tomato[pos_x + dx[i]][pos_y + dy[i]][pos_z + dz[i]] = 1;
						a.push_back(pos_x + dx[i]);
						a.push_back(pos_y + dy[i]);
						a.push_back(pos_z + dz[i]);
						q.push(a);
						a.clear();
					}
				}
			}//(for) 상,하,좌,우,위,아래 6가지의 경우를 생각
		}
		cnt++;
	}
}

int main() {
	bool flag = false;
	bool check0=false;
	bool check1=false;
	cin >> n;
	cin >> m;
	cin >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {

				cin >> tomato[i][j][k];


				if (tomato[i][j][k] == 0) {
					check0 = true;
				}

				else if (tomato[i][j][k] == 1) {
					check1 = true;
					a.push_back(i);
					a.push_back(j);
					a.push_back(k);
					q.push(a);
					a.clear();
					check[i][j][k] = true;
				}
			}
		}
	}
	if (check1&&!check0) {
		cout << "0";
		return 0;
	}//이미 토마토가 모두 익어있을때
	else if (!check1 && !check0) {
		cout << "-1";
		return 0;
	}//모두 -1, 즉 모두 비어있을때 
	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (tomato[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}//토마토를 익힌 후에도 익지 않은 토마토가 남아있으면 "-1"
	cout << cnt-1;//토마토를 모두 익힐수 있을떄의 최소 일수 
	return 0;
}
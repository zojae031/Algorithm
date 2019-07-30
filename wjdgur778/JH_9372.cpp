#include<iostream>
#include<vector>
using namespace std;
//상근이의 여행
//dfs, bfs
//최소간선으로 모든 정점을 방문해라
int t;
int n;
int m;
vector <vector <int>> trip;
vector <int>check;
int cnt = 0;

int dfs(int n) {

	check[n] = true;
	for (int i = 0; i < trip[n].size(); i++) {
		if (check[trip[n][i]] == false) {
			cnt++;
			dfs(trip[n][i]);
		}
	}
	return cnt;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {

		cin >> n >> m;
		cnt = 0;
		check = vector<int>(n+1, false);
		trip = vector<vector <int>>(n + 1);
		for (int j = 0; j < m; j++) {
			int a;
			int b;
			cin >> a >> b;
			trip[a].push_back(b);
			trip[b].push_back(a);
		}
		cout << dfs(1)<<endl;
	}

	return 0;

}
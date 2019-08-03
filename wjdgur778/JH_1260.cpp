#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//dfs¿Í bfs


int n;
int m;
int v;
vector<bool>check = vector<bool>(1001, false);
vector<vector<int>> map = vector<vector<int>>(10001);
queue<int> q;

void dfs(int v) {
	cout << v << " ";
	check[v] = true;
	for (int i = 0; i < map[v].size(); i++) {
		if (check[map[v][i]] == false) {
			dfs(map[v][i]);
		}
	}
}



void bfs(int v) {
	int a;
	int size;

	while (!q.empty()) {
		a = q.front();
		cout << a << " ";
		q.pop();
		for (int i = 0; i < map[a].size(); i++) {
			if (check[map[a][i]] == false) {
				check[map[a][i]] = true;
				q.push(map[a][i]);
			}
		}
	}

}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		sort(map[i].begin(), map[i].end());
	}

	dfs(v);

	cout << endl;
	check = vector<bool>(1000, false);
	q.push(v);
	check[v] = true;

	bfs(v);


	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//이분 그래프
//시작점과 끝점의 그룹이 서로 달라야 이분 그래프
//dfs
//탐색하지 않은 간선도 탐색해야됨
int tmp;
int t;
int v, e;
vector <int> check;
bool ans=true;
vector <vector<int>> arr;

void dfs(int n, int color) {
	check[n] = color;
	for (int j = 0; j < arr[n].size(); j++) {
		if (check[arr[n][j]] == check[n]) {
			ans = false;
			return;
		}//비교하면서 같으면 이분그래프가 될수 없다
		if (check[arr[n][j]] == 0) {
			dfs(arr[n][j], 3 - color);
		}//탐색하지 않은 곳에서만 dfs실행
	}
	return;
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		check = vector<int>(v + 1, 0);
		arr = vector<vector<int>>(v + 1);
		for (int j = 0; j < e; j++) {
			int a;
			int b;
			cin >> a;
			cin >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}//입력

		for (int i = 1; i <= v; i++) {
			if(check[i]==0) dfs(i, 1);
		}//서로 연결 되어있지 않은 정점도 탐색해주어야함 /*1-2, 3-4*/ 처럼
		if (ans) cout << "YES"<<endl;
		else cout << "NO"<<endl;
		ans = true;
	}
	return 0;
}
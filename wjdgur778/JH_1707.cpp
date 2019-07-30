#include<iostream>
#include<vector>
using namespace std;

//�̺� �׷���
//�������� ������ �׷��� ���� �޶�� �̺� �׷���
//dfs
//Ž������ ���� ������ Ž���ؾߵ�
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
		}//���ϸ鼭 ������ �̺б׷����� �ɼ� ����
		if (check[arr[n][j]] == 0) {
			dfs(arr[n][j], 3 - color);
		}//Ž������ ���� �������� dfs����
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
		}//�Է�

		for (int i = 1; i <= v; i++) {
			if(check[i]==0) dfs(i, 1);
		}//���� ���� �Ǿ����� ���� ������ Ž�����־���� /*1-2, 3-4*/ ó��
		if (ans) cout << "YES"<<endl;
		else cout << "NO"<<endl;
		ans = true;
	}
	return 0;
}
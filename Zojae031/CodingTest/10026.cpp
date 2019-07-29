#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {

	string input;
	int n;
	cin >> n;
	queue<pair<int,bool>> q;
	vector<vector<pair<int, bool>>> v(n);//적록색약이 아닌사람
	vector<vector<pair<int, bool>>> v2(n);//적록색약 인사람
	getchar();

	//R(0), G(1), B(2) 형태로 배열에 저장하는 동작
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		for (int j = 0; j < n; j++) {
			switch (input[j]) {
			case 'R': {
				v[i].push_back(make_pair(0, false));
				v2[i].push_back(make_pair(0, false));
				break;
			}
			case 'G': {
				v[i].push_back(make_pair(1, false));
				v2[i].push_back(make_pair(0, false));
				break;

			}
			case 'B': {
				v[i].push_back(make_pair(2, false));
				v2[i].push_back(make_pair(2, false));
				break;
			}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if()
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << v[i][j].first;
		cout << endl;
	}
	return 0;
}
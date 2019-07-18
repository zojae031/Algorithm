#include<iostream>
#include <queue>
using namespace std;

int main() {
	
	int n, m;
	int num;
	int data;
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		int cnt = 0;
		cin >> n >> m;
		priority_queue<pair<int, bool>/*stable 비교 연산자 함수 구현*/> q;
		for (int j = 0; j < n; j++) {
			cin >> data;
			bool flag = j == m ? true : false;
;			q.push(pair<int, bool>(data,flag));
		}
		while (true) {
			pair<int, bool> front = q.top();
			q.pop();
			cnt++;
			if (front.second) {
				cout << cnt << endl;
				break;
			}
		}
	}
	


	return 0;
}
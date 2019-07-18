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
		queue<pair<int, int>> q;
		int arr[10] = { 0 };

		cin >> n >> m;
		
		for (int j = 0; j < n; j++) {
			cin >> data;
			arr[data]++;
			q.push(pair<int, int>(data, j));
		}
		bool flag = true;
		while (flag) {
			pair<int, int> front = q.front();
			q.pop();
			for (int j = 9; j >= front.first; j--) {
				if (j == front.first) {
					cnt++;
					arr[j] = 0;
					if (front.second == m) {
						cout << cnt << endl;
						flag = false;
						break;
					}
					break;
				}
				if (arr[j] > 0) {//만약 나보다 큰 값이 있다면 푸쉬
					q.push(front);
					break;
				}
			}
			
		
		}
	}



	return 0;
}
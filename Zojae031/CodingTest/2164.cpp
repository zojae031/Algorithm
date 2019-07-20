#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		q.push(i+1);
	}

	while (true) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		int front = q.front();
		
		q.push(front);
		q.pop();
		
	}
	

	return 0;
}
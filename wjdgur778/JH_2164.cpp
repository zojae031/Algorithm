#include<iostream>
#include <deque>
using namespace std;

//카드2
//덱 사용

deque <int> d;
int solution(int n) {
	for (int i = 1; i < n+1; i++) {
		d.push_back(i);
	}
	while (d.size() != 1) {
		int a;
		d.pop_front();
		//버리고
		a=d.front();
		d.pop_front();
		d.push_back(a);
	}
	return d.front();
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}
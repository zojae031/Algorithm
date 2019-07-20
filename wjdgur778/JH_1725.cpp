#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
//히스토그램
//스택
//너비 구하기가 중요
int n;
int histo[100002] = { -1 };
stack <int> s;
int solution() {
	int a = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		histo[i] = a;
	}

	int tmp = 0;
	int top;
	int i;
	s.push(0);

	for (i = 1; i <=n; i++) {
		int a;
		while (!s.empty() && histo[s.top()] > histo[i]) {
			top = s.top();
			s.pop();
			if (s.empty())a = i;
			else a=i-s.top()-1 ;//너비
			tmp = max(tmp, (histo[top]*a));//(너비 * 높이)
		                                   //높이 :스택의 탑 (현재까지 가장 큰 값)
		}
		s.push(i);
	}

	return tmp;
}
int main() {
	cin >> n;
	cout << solution();
	return 0;
}



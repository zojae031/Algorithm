#include<iostream>
#include<stack>
using namespace std;

//외계인의 기타 연주 
//스택 
int n;
int p;

int solution() {

	stack <int> s[6];
	int a;
	int b;
	int cnt = 0;

	for (int i = 0; i < n; i++) {

		cin >> a;
		cin >> b;
		a -= 1;

		if (s[a].empty()) {
			s[a].push(b);
			cnt++;
			continue;
		}//비어있으면 스텍에 넣고 카운트
		else
		{
			if (s[a].top() < b) {
				s[a].push(b);
				cnt++;
			}//들어오려하는 값이 스택의 값보다 크면 푸쉬
			else if (s[a].top() == b) {
				continue;
			}//같으면 아무런 동작 x
			else {
				while (!s[a].empty() && s[a].top() > b) {
					s[a].pop();
					cnt++;
				}
				if (!s[a].empty() && s[a].top() == b) {
					continue;
				}
				s[a].push(b);
				cnt++;
			}//값이 스택의 값보다 작으면 
			 //커질때 까지 팝을 하면서 카운트
		}
	}//입력을 하면서 비교

	return cnt;
}

int main() {
	cin >> n;
	cin >> p;
	cout << solution();
	return 0;
}

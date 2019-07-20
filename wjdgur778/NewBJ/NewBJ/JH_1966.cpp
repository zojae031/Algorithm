#include<iostream>
#include<deque>
using namespace std;

// 프린터 큐
//덱 사용 

int t;
int n;
int index;
int a;
int cnt = 0;
bool flag = false;

int solution() {

	pair<int, bool> tmp;
	deque<pair<int, bool>> deque;
	cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> tmp.first;
		tmp.second = 0;
		if (index == i)
			tmp.second = 1;
		deque.push_back(tmp);
	}
	if (deque.empty())return 0;
	while (!deque.empty()) {

		flag = false;
		tmp = deque.front();
		deque.pop_front();
		cnt++;

		if (deque.empty()) return cnt;

		for (int i = 0; i < deque.size(); i++) {
			if (tmp.first < deque[i].first) {
				flag = true;
				break;
			}
		}//자신을 뺀 나머지 덱에 있는 

		if (flag) {
			deque.push_back(tmp);
			cnt--;
		}
		else {
			if (tmp.second == 1) return cnt;
		}
		
	}
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> index;
		cout << solution();
		if(i!=t-1)
		cout<<endl;
	}

	return 0;
}
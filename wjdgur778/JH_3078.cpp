#include<iostream>
#include<string>
#include<queue>

//좋은 친구
//큐

using namespace std;
int n;
int k;
string f;
int friends[300000];
queue <int> q[21];//이름의 길이 만큼의 큐 배열 선언

long long solution() {
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> f;
		friends[i] = f.length();

		if (q[friends[i]].empty()) {
			q[friends[i]].push(i);
		}//비어있으면 큐에 삽입
		else {
			while (i - q[friends[i]].front() > k) {
				q[friends[i]].pop();
				if (q[friends[i]].empty()) {
					break;
				}//현재 들어오는 친구와 큐안의 친구가 좋은 친구가 아니면 pop
			}
			ans += q[friends[i]].size();//좋은 친구만 남았을때 좋은 친구의 쌍을 추가
			q[friends[i]].push(i);//이후 현재의 친구를 큐에 삽입
		}
	}
	return ans ;
}//입력값을 받으면서 이름의 길이를 큐의 인덱스로 보고, 길이에 해당하는 인덱스를 큐의 값으로 넣어준다.
int main() {
	cin >> n;
	cin >> k;

	cout << solution();

	return 0;
}


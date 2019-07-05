#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int n, m, k;//n :여자2, m :남자1, k : 인턴쉽
	int team = 0;
	int cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	//case 1 : 남은 n과 m으로 k를 채울 수 있니?
	//else : 못채우면 종료
	//case 2 : 만약 팀을 만들 수 있나?
	//else : 못만들면 종료
	while (true) {
		if (n - 2 + m - 1 >= k) { //case 1
			if (n - 2 >= 0 && m - 1 >= 0) {
				n -= 2;
				m -= 1;
				team++;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
		
	}
	printf("%d", team);
	return 0;
}
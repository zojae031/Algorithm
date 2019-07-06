#include <iostream>
using namespace std;

//대회 of 인턴
//조건을 만족하는 식을 만들어 구한다

int solution(int n, int m, int k) {

	int ans;
	int tmp;
	for (int i = 0; i < 100; i++) {

		if (n >= 2 * i&&m >= i) {
			tmp = (n + m - k) / 3;
			if (tmp >= i) {
				ans = i;
			}

		}
	}
	return ans;

}

int main() {

	int n;//여자 수
	int m;//남자 수
	int k;//인턴 수 
	cin >> n >> m >> k;
	cout << solution(n, m, k);

	return 0;
}

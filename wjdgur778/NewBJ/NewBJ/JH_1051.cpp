#include<iostream>
using namespace std;

//숫자 정사각형
//브루트포스


int n;
int m;
int map[51][51] = { 0 };

int solution() {
	int ans=1;//1개의 숫자로만 이루어진 경우 0이 아닌 1로 초기화
	int cnt = 1;


	while (cnt < n&&cnt < m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + cnt < n  && j + cnt < m) {
					if (map[i][j] == map[i][j + cnt]&& map[i][j]==map[i + cnt][j + cnt]&& map[i][j]==map[i+cnt][j]) {
						ans = cnt + 1;
					}
				}

			}

		}
		cnt++;
	}
	return ans;
}

int main() {

	cin >> n >> m;
	char a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			cin >> a;
			map[i][j] = a - '0';
		}
	}


	cout << solution()*solution();
	return 0;
}
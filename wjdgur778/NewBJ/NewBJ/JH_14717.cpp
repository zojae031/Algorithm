#include <iostream>
using namespace std;

//앉았다 (섯다의 간단한 버전)
//아직 못품



int solution(int n, int m) {
	float result;
	int cnt = 0;
	for (int i = 1; i < 11; i++) {

		for (int j = 1; j < 11; j++) {

			if (i != n && j != m) {

				if (i != j) {
					if ((i + j) % 10 == 1)
						cnt++;
					if ((i + j) % 10 == 2)
						cnt++;
					if ((i + j) % 10 == 0)
						cnt++;
				}
			}


		}
	}
	result = cnt;




	return result;
}

int main() {

	int n;
	int m;
	cin >> n >> m;

	cout << solution(n, m);



	return 0;
}
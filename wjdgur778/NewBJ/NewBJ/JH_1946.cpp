#include<iostream>
#include<algorithm>
using namespace std;

//신입 사원
//그리디 알고리즘
//시간 복잡도 생각
int n;
int m;

int solution() {
	bool flag = false;
	int ans = 0;
	int tmp;
	cin >> m;
	pair <int, int> *grade = new pair <int, int>[m];


	for (int i = 0; i < m; i++) {
		cin >> grade[i].first >> grade[i].second;
	}
	sort(grade, grade + m);

	tmp = grade[0].second;
	//현재의 최솟값보다 최소이면 합격
	//오름차순이기때문에(서류 성적이 오름차순) 나보다 나중인 사람들은 볼필요 없고
	//현재까지의 지원자들 중 면접 점수만 잘보면 된다.
	for (int i = 1; i < m; i++) {
		if (tmp > grade[i].second) {
			tmp = grade[i].second;
			ans++;
		}
	}


	return  ans + 1;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << solution()<<endl;

	}

	return 0;

}

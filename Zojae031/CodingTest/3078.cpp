#include<iostream>
#include <string>
#include<vector>
#include<list>
using namespace std;
int main() {
	int n, k;
	long long cnt = 0;
	int deleteIndex = 0;
	cin >> n>> k;
	getchar();
	
	vector<int>v;
	vector<int> windows(21);
	string data;
	for (int i = 0; i < n; i++) {
		getline(cin, data);
		v.push_back(data.length());
	}

	
	for(int i=0 ; i<n ; i++){
		deleteIndex = i - k - 1;//윈도우 사이즈 i:현재 인덱스, k:윈도우크기, 1:나로부터 다음칸부터 시작
		//뒤에꺼 제거
		if (deleteIndex >= 0 && windows[v[deleteIndex]] > 0) {
			windows[v[deleteIndex]]--;
		}
		//비교할 사이즈구하기
		int compare = v[i];
		//만약 해당 범위안에 존재하면 카운팅
		if (windows[compare] > 0) {
			cnt+=windows[compare];
		}
		//윈도우 진입
		windows[compare]++;
	}
	
	cout << cnt;
	return 0;
}

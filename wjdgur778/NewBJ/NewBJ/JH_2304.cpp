#include <iostream>
#include <algorithm>
using namespace std;

//창고 다각형


int n;

int solution() {
	int max=0;
	int index;
	int size=0;
	pair <int, int> *pillar = new pair <int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> pillar[i].first >> pillar[i].second;
	}//기둥 입력
	sort(pillar, pillar + n);//인덱스 정리
	for (int i = 0; i < n; i++) {
		if (max < pillar[i].second) {
			max = pillar[i].second;
			index = i;
		}
	}//입력4
	int i=0;
	while (i < index) {
		for (int j = 1; i+j <= index; j++) {
			if (pillar[i].second <= pillar[i+j].second) {
				size += pillar[i].second *(pillar[i+j].first - pillar[i].first);
				i = i+j;
				break;
			}
		}
	}//가장 긴 기둥을 기준으로 좌측
	i = n-1;
	while (i > index) {
		for (int j = 1; j <=n-index; j++) {
			if (pillar[i].second <= pillar[i-j].second) {
				size += pillar[i].second *(pillar[i].first - pillar[i-j].first);
				i =i-j ;
				break;
			}
		}
	}//가장 긴 기둥을 기준으로 우측
	return size + max;//좌 + 우 + 중간기둥(max)

}


int main() {
	cin >> n;//기둥 갯수
	cout << solution();
	return 0;
}
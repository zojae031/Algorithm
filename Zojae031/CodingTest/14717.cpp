#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int arr[2];
	double result = 0.0;
	int cnt = 0;
	for(int i=0 ;i <2 ; i++)
	scanf("%d", &arr[i]);
	//땡
	if (arr[0] == arr[1]) {
		result = (143 + arr[0])/ 153.0 ; //일반항 도출해버림
	}
	else {//끗
		int g = (arr[0] + arr[1]) % 10;
		for (int i = 1; i <= 10; i++) {
			if (i == arr[0] || i == arr[1]) continue; //만약 영학이가 이미 뽑은 카드면 스킵
			for (int j = 1; j <= 10; j++) {
				if ((i != j) && ((i + j) % 10 < g)) {// 땡이 아니고 && 끗보다 작은 경우
					cnt++;
				}
			}
		}
		cnt*= 2;
		/*
		1 2 3 4 5 6 7 8 9 10 : i
		1 2 3 4 5 6 7 8 9 10 : j
		-> (2i,8j), (8i,2j) 만 계산하지만 실제로는 (2i,8i), (2j,8j)도 존재하기 때문에 cnt x 2를 해준다
		*/
		result = cnt / 153.0;
	

	}
	printf("%.3lf", result);
	return 0;
}

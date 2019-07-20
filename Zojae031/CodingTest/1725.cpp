#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int * arr;
	int n;
	int input;

	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	int max = n; //가로축 정사각형 넓이를 일단 최고로 잡아둔다.

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[i] = input;
	}


	int cnt = 1;
	int i = 0, j = 0;
	while (i < n) {// n
		int base = arr[i++];
		if (max < base) { //단일 직사각형 높이 비교
			max = base;
		}
		j = i;
		while (j < n) { //n
			if (base - arr[j] <= 0) {//만약 내 높이 - 다음 높이 < 0
				j++;
				cnt++;
				if (max < base * cnt) {
					max = base * cnt;
				}
			}
			else { // 내 높이 - 다음 높이 >0
				base--;//내 자신을 하나 씩 깎으며 계산함
			}

		}
		cnt = 1;
	}

	//	O(n^2)
	printf("%d",max);

	return 0;
}


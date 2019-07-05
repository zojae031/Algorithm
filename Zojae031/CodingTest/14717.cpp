#include<iostream>
using namespace std;
int main() {
	int arr[2];
	double result = 0.0;
	for(int i=0 ;i <2 ; i++)
	scanf("%d", &arr[i]);
	//¶¯
	if (arr[0] == arr[1]) {
		result += 0.5;
		for (int i = 0; i < 10; i++) {
			if (arr[0] == i) {
				// È®·ü°è»ê½Ä
				/*
				(10- arr[0]) /  9 + 9c2
				*/
			}
		}
	}
	else {//²ý
		int g = (arr[0] + arr[1]) % 10;
		/*
		 ()/8 + 
		*/

	}
	printf("%lf.3", result);
	return 0;
}
/*
1²ý
1-> 1,0 : 1°³
11 -> 1,10 / 2,9 / 3,8 / 4,7/ 5,6 : 5°³
2²ý
2 -> 0,2 / 1,1  - 1 : 1°³
12 -> 10, 2 / 9,3 / 8,4 / 7,5 / 6,6 -1 :4°³
3²ý
3 -> 0,3 / 1,2: 2°³
13 -> 
*/
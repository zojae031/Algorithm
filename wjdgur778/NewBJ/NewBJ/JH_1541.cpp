#include <iostream>
#include<string>
using namespace std;

//잃어버린 괄호
//입력하는 방법은??
//그리디 알고리즘
//처음에 '-'가 오면 그 이후의 수들을 모조리 빼주면 최솟값

string calc="";

int solution() {
	bool flag=false;
	int result = 0;
	string tmp;
	for (int i = 0; i <= calc.size(); i++) {

		//숫자를 tmp에 담아놓고 다음에 오는 연산자를 본후 계산을 함으로
		//'\0'까지 확인하여 마지막에 남는 계산까지 해준다,만일 하지않으면 마지막에 있는 숫자가 연산이 안됨

		if (calc[i] == '+' || calc[i] == '-'||calc[i]=='\0') {

			if (flag) {
				result -= stoi(tmp);
				tmp = "";
			}
			else {
				result += stoi(tmp);
				tmp = "";
			}
			if (calc[i] == '-')
				flag = true;
		}
		//연산자이면

		else
			tmp += calc[i];
		//연산자가 아니면
		
	}


	return result;
}

int main() {

	cin >> calc;
	cout << solution();




	return 0;
}
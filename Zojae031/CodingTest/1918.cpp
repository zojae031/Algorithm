#include<iostream>
#include <stack>
#include<string>
using namespace std;
#pragma warning (disable:4996)
/*
+,- : 1
*,/ : 2
(,) : 3
*/
int main() {
	stack<pair<char, int>> s;
	string str;
	char ch = '\0';
	/*
	연산자 비교 순위 높으면 그대로 푸쉬
	연산자 비교 순위 낮거나 같으면 바꿔 넣음
	*/
	getline(cin, str);
	int idx = 0;
	while (idx!=str.size()) {
		ch = str[idx++];
		if (ch == '(') {//괄호
			s.push(pair<char, int>(ch, 0));
		}
		else if (ch == ')') {//닫는 괄호5
			while (s.top().first != '(') {
				printf("%c", s.top().first);
				s.pop();
			}
			s.pop();
		}
		else if (ch >= 'A' && ch <= 'Z') {//피연산자
			printf("%c", ch);
		}
		else {//연산자
			pair<char, int> p;
			switch (ch)
			{
			case '+': p.second = 1; break;
			case '-': p.second = 1; break;
			case '*': p.second = 2; break;
			case '/': p.second = 2; break;
			}
			p.first = ch;


			while (!s.empty() && s.top().second >= p.second) {//자기보다 우선순위 낮은 연산자 만날 때 까지
				printf("%c", s.top().first);
				s.pop();
			}

			s.push(p);
		}
	}


	while (!s.empty()) {
		printf("%c", s.top().first);
		s.pop();
	}
	return 0;
}

/*
A*(B+C)
A+(B*C)*D*E+F
(A+(B*C))-(D/E)
A+B*C+D
*/
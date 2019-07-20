#include<iostream>
#include<string>
#include<stack>
using namespace std;

//후위연산식
//스택이용
//

string s;
string ans;
stack <char> stck;
string solution() {

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '*'&&s[i] != '/'&&s[i] != '+'&&s[i] != '-'&&s[i] != '('&&s[i] != ')') {
			ans += s[i];
		}
		else {
			if (stck.empty()) {
				stck.push(s[i]);
			}
			else {
				switch (s[i])

				{
				case '(':
					stck.push(s[i]);
					break;
				case ')':
					while (stck.top() != '(') {
						ans += stck.top();
						stck.pop();
					}
					stck.pop();
					break;
				case '+':
				case '-':
					while (!stck.empty() && (stck.top() != '(')) {
						ans += stck.top();
						stck.pop();
					}
					stck.push(s[i]);
					break;
				case '*':
				case'/':
					while (!stck.empty() && (stck.top() == '/' || stck.top() == '*')) {
						ans += stck.top();
						stck.pop();
					}
					stck.push(s[i]);
					break;
				}
			}
		}
	}//연산자들을 스택에 넣어가면서 풀이
	 //연산자의 우선순위에 따라 스택안의 연산자가 현재의 연산자보다 우선순위가 높으면 꺼내어 문자열에 붙힌다.
	while (!stck.empty()) {
		ans += stck.top(); stck.pop();
	}
	return ans;
}

int main() {
	cin >> s;
	cout << solution();
	return 0;
}
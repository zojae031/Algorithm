#include <iostream>
#include <stack>
#include <string>


using namespace std;
string input = "";
stack<char> s;

int main() {

    cin >> input;


    for (int i = 0; i < input.length(); ++i) {

        if (input[i] >= 'A' && input[i] <= 'Z') cout << input[i];
        else if (input[i] == '(') s.push(input[i]);
        else if (input[i] == ')') {
            while (s.top() != '(') { cout << s.top(), s.pop(); }
            s.pop();
        } else {
            while (!s.empty()) {
                if (input[i] == '+' && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))
                    cout << s.top(), s.pop();
                else if (input[i] == '-' && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))
                    cout << s.top(), s.pop();
                else if (input[i] == '*' && (s.top() == '/' || s.top() == '*'))cout << s.top(), s.pop();
                else if (input[i] == '/' && (s.top() == '*' || s.top() == '/'))cout << s.top(), s.pop();
                else break;
            }
            s.push(input[i]);
        }
    }

    while (!s.empty()) cout << s.top(), s.pop();


}
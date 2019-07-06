#include <cstdio>
#include <string>

using namespace std;

inline int min(int a, int b) {
    return a < b ? a : b;
}

int N, M, ans = 1000000;
int button[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


void f(string num) {
    for (int i = 0; i < 10; ++i) {
        if (button[i]) {
            string temp = num + to_string(i);
            ans = min(ans, abs(N - stoi(temp)) + temp.length());
            if (temp.length() < 6) f(temp);
        }
    }

}

int main() {

    scanf("%d %d", &N, &M);

    ans = min(ans, abs(100 - N));
    for (int i = 0, a; i < M; ++i) scanf("%d", &a),button[a] = 0;
    if (M < 10) f("");
    printf("%d", ans);
}
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
int n, p, a, b, ans = 0;
vector<stack<int>> v(6);

int main() {

    scanf("%d %d", &n, &p);

    for (int i = 0; i < n; ++i) {

        scanf("%d %d", &a, &b), a--;
        if (v[a].empty() || v[a].top() < b) v[a].push(b), ans++;
        else {
            while (!v[a].empty() && v[a].top() > b) v[a].pop(), ans++;
            if (v[a].empty() || v[a].top() < b) v[a].push(b), ans++;
        }
    }
    printf("%d", ans);

}
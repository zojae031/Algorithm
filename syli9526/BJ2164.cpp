#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;
int n, ans;

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) q.push(i);

    while (!q.empty()) {
        ans = q.front(), q.pop();
        if (!q.empty()) q.push(q.front()), q.pop();
    }
    printf("%d", ans);
}
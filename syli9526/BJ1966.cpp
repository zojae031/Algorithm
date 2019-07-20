#include <iostream>
#include <queue>

using namespace std;

int T, N, M, P, ans, idx, value;


int main() {

    cin >> T;

    for (int i = 0; i < T; ++i) {
        ans = 0;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int j = 0; j < N; ++j) {
            cin >> P;
            q.push({j, P});
            pq.push(P);
        }
        while (!q.empty()) {
            idx = q.front().first;
            value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ans++;
                if (idx == M) {
                    cout << ans << endl;
                    break;
                }
            } else q.push({idx, value});
        }
    }
}
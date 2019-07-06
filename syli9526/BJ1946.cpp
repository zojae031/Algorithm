#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, ans;
vector<pair<int, int>> v;

int main() {

    scanf("%d", &T);

    while (T--) {
        ans = 0;
        scanf("%d", &N);
        for (int i = 0, a, b; i < N; ++i) scanf("%d %d", &a, &b), v.push_back({a, b});
        sort(v.begin(), v.end());
        for (int i = 0; i < N; ++i) {
            for (int j = i - 1; j >= 0; j--) {
                if (v[i].second > v[j].second) {
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n", N - ans);
        v.clear();
    }

}
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 50;

int N, M, map[MAX][MAX], ans = 1, d;

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%1d", &map[i][j]);


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            d = 1;
            while (i + d < N && j + d < M) {
                if (map[i][j] == map[i + d][j + d] && map[i][j] == map[i][j + d] && map[i][j] == map[i + d][j]) ans = max(ans, d + 1);
                d++;
            }
        }
    }

    printf("%d", ans * ans);
}
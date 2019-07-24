#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 20001;

int K, V, E;
vector<int> v[MAX];
int setNum[MAX]; // 1 or 2;

void dfs(int node, int num) {

    setNum[node] = num;
    for (int i = 0; i < v[node].size(); ++i) {
        int next = v[node][i];
        if (setNum[next] == 0) dfs(next, 3 - num);
    }
}

bool check() {

    for (int i = 1; i < V; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            int next = v[i][j];
            if (setNum[i] == setNum[next]) return false;
        }
    }

    return true;

}

int main() {

    scanf("%d", &K);

    while (K--) {

        for (int i = 0; i < MAX; ++i) v[i].clear();
        for (int i = 0; i < MAX; ++i) setNum[i] = 0;


        scanf("%d %d", &V, &E);

        for (int i = 0; i < E; ++i) {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }

        for (int j = 1; j < V; ++j) if (setNum[j] == 0) dfs(j, 1);

        if (check()) printf("YES\n");
        else printf("NO\n");


    }
}
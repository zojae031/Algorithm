#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;
typedef long long ll;

int n, k, length[21] = {0,};
vector<int> v;
char temp[21] = "";
ll ans = 0;

int main() {

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", temp);
        v.push_back(strlen(temp));
        ans += length[v[i]]++;
        if (i < k) continue;
        length[v[i - k]]--;
    }
    printf("%lld", ans);

}
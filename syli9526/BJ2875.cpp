#include<cstdio>
#include<algorithm>
int n, m, k;
int main() {
    scanf("%d %d %d", &n, &m, &k);
    printf("%d", std::min({(n + m - k) / 3, n / 2, m}));
}
#include <cstdio>
#include <stack>

using namespace std;
const int MAX = 2 << 17;
int n, ans = 0, idx, w;
int histogram[MAX];
stack<int> st;

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &histogram[i]);

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && histogram[st.top()] > histogram[i]) {
        
            idx = st.top(), st.pop();
            if (st.empty()) w = i;
            else w = i - st.top() - 1;
            ans = max(ans, histogram[idx] * w);
        }
        st.push(i);
    }

    printf("%d", ans);
    return 0;
}

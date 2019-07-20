#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
vector<pair<int, int>> m;
int* s;

int main() {
	int n, i, t, ans;
	int w, h;
	int mh = 0;
	bool flag = true;
	scanf("%d", &n);
	s = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &w, &h);
		mh = max(mh, h);
		m.push_back(make_pair(w, h));
	}
	sort(m.begin(), m.end(), compare);
	s[0] = 0;
	flag = mh != m[0].second;
	w = 1;
	for (i = 1, t = 1; i < n; i++) {
		if (flag && m[s[t - 1]].second < m[i].second) {
			s[t++] = i;
			flag = mh != m[i].second;
			w = t;
		}
		else if (!flag) {
			if (w == t || m[s[t - 1]].second > m[i].second) s[t++] = i;
			else {
				while (w < t && m[s[t - 1]].second <= m[i].second) t--;
				s[t++] = i;
			}
		}
	}
	ans = 0;
	for (i = t - 1; i >= 0; i--) {
		if (i >= w)
			ans += ((m[s[i]].first - m[s[i - 1]].first)*m[s[i]].second);
		else if (i == (w - 1))
			ans += m[s[i]].second;
		else
			ans += ((m[s[i + 1]].first - m[s[i]].first)*m[s[i]].second);
	}
	printf("%d", ans);

	return 0;
}
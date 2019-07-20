#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> d;
inline bool compare_pair(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
	int t, size, i, ans;
	int f, s, now;
	scanf("%d", &t);

	while (t--) {
		scanf("%d",&size);

		for (i = 0; i < size; i++) {
			scanf("%d %d", &f, &s);
			d.push_back(make_pair(f, s));
		}

		sort(d.begin(), d.end(), compare_pair);
		now = d[0].second;
		ans = 1;
		for (i = 1; i < size; i++) {
			if (d[i].second < now) {
				now = d[i].second;
				ans++;
			}
		}
		printf("%d\n",ans);
		d.clear();
	}

	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int n, area = 0;
vector<pair<int, int>> v;
pair<int, int> temp;

// 오름차순 정렬을 위한 비교 함수
inline bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {

    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i) scanf("%d %d", &a, &b), v.push_back({a, b});
    // 정렬
    sort(v.begin(), v.end(), cmp);

    temp = v[0];
    for (int i = 0; i < n; ++i)
        // 높이가 높아지면
        if (temp.second <= v[i].second)
            // 전에 저장했던 높이*(현재위치 - 전에 저장했던 위치)를 총 넓이에 더해줌
            area += (v[i].first - temp.first) * temp.second, temp = v[i];
    //최고 높이일때 더해줌 
    area += temp.second;

    temp = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
        if (temp.second < v[i].second)
            area += (temp.first - v[i].first) * temp.second, temp = v[i];

    printf("%d", area);

}

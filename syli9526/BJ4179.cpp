#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;

// 그래프의 네방향으로 움직이기위한 배열
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};

int R, C, ans = 0;
char map[MAX][MAX];

queue<pair<int, int>> fire;
queue<pair<int, int>> user;

int bfs() {


    while (!user.empty()) {

        int cr, cc;
        unsigned long size;

        size = fire.size();

        // 불 번짐을 먼저 실행
        while (size--) {
            cr = fire.front().first;
            cc = fire.front().second;

            fire.pop();

            //불을 네방향으로 이동해줌
            for (int i = 0; i < 4; ++i) {
                if (cr + dr[i] < 0 || cr + dr[i] >= R || cc + dc[i] < 0 || cc + dc[i] >= C) continue;
                if (map[cr + dr[i]][cc + dc[i]] == '.' || map[cr + dr[i]][cc + dc[i]] == 'J') {
                    map[cr + dr[i]][cc + dc[i]] = 'F';
                    fire.push({cr + dr[i], cc + dc[i]});
                }
            }
        }

        size = user.size();

        // 유저 이동
        while (size--) {
            cr = user.front().first;
            cc = user.front().second;

            user.pop();

            //유저를 네방향으로 이동해줌
            for (int i = 0; i < 4; ++i) {
                if (cr + dr[i] < 0 || cr + dr[i] >= R || cc + dc[i] < 0 || cc + dc[i] >= C) return ++ans;
                if (map[cr + dr[i]][cc + dc[i]] == '.' ) {
                    map[cr + dr[i]][cc + dc[i]] = 'J';
                    user.push({cr + dr[i], cc + dc[i]});
                }
            }
        }
        ans++;
    }
    // 그래프 내부에 유저가 없는데 리턴이 되지 않았다면 탈출을 못한것
    return -1;

}

int main() {

    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; ++i) {
        scanf("%s", map[i]);
        for (int j = 0; j < C; ++j) {
            if (map[i][j] == 'J') user.push({i, j});
            else if (map[i][j] == 'F') fire.push({i, j});
        }
    }

    ans = bfs();
    if (ans == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);

}

#include<iostream>
#include<cstring>

using namespace std;

int n;

char map[101][101];
bool visit[101][101];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int cnt, rg_cnt;

int f(int x, int y) {

    char &ret = map[x][y];

    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= n && ny <= n && nx > 0 && ny > 0 && !visit[nx][ny]) if (ret == map[nx][ny]) f(nx, ny);

    }

    return ret;

}

int rgf(int x, int y) {

    char &ret = map[x][y];

    visit[x][y] = true;


    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= n && ny <= n && nx > 0 && ny > 0 && !visit[nx][ny]) {

            if (ret == map[nx][ny]) rgf(nx, ny);
            else if ((ret == 'R' && map[nx][ny] == 'G') || (ret == 'G' && map[nx][ny] == 'R')) rgf(nx, ny);

        }

    }

    return ret;

}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) cin >> map[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visit[i][j]) cnt++, f(i, j);
        }
    }
    memset(visit, false, sizeof(visit));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visit[i][j]) rg_cnt++, rgf(i, j);
        }

    }

    cout << cnt << " " << rg_cnt << endl;

    return 0;

}
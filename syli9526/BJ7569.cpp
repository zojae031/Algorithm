//
//  main.cpp
//  BJ7569
//
//  Created by 소율 on 02/08/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

int m, n, h, cnt;
int tomato[100][100][100];
int visit[100][100][100];
int dir[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };

struct pos {
    int x, y, z;
};
queue<pos> q;

int bfs() {
    int ans = 1;
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            pos c1 = q.front();
            q.pop();
            int x = c1.x, y = c1.y, z = c1.z;
        
            if (visit[x][y][z])
                continue;
            else
                visit[x][y][z] = 1;
            
            for (int j = 0; j < 6; ++j) {
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                int nz = z + dir[j][2];
                
                if (nx < 0 || nx >= h ||ny < 0 || ny >= n||nz < 0 || nz >= m) continue;
                
                if (tomato[nx][ny][nz] == -1) continue;
                
                if (tomato[nx][ny][nz] == 0) {
                    q.push({ nx,ny,nz });
                    tomato[nx][ny][nz] = 1;
                    cnt--;
                }
                
                if (cnt == 0)
                    return ans;
            }
        }
        ans++;
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &m, &n, &h);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                scanf("%d", &tomato[i][j][k]);
                if (tomato[i][j][k] == 0)
                    cnt++;
                else if (tomato[i][j][k] == 1)
                    q.push({ i,j,k });
            }
        }
    }
    printf("%d\n", bfs());
    
    return 0;
}

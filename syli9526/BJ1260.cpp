//
//  main.cpp
//  BJ1260
//
//  Created by 소율 on 01/08/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include<iostream>
#include <stdio.h>
#include<queue>

using namespace std;
const int MAX = 1001;
int N, M, V;
int map[MAX][MAX];
int visit[MAX];

void dfs(int v) {
    
    printf("%d ", v);
    visit[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1 || map[v][i] == 0) continue;
        dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = 0;
    while (!q.empty()) {
        v = q.front();
        printf("%d ", q.front());
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 0 || map[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}

int main() {
    
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0, x, y; i < M; i++)
        scanf("%d %d", &x, &y), map[x][y] = map[y][x] = 1;
    dfs(V);
    printf("\n");
    bfs(V);
    return 0;
}

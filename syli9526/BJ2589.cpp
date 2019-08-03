//
//  main.cpp
//  BJ2589
//
//  Created by 소율 on 01/08/2019.
//  Copyright © 2019 소율. All rights reserved.
//
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 50;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int L, W;
string map[MAX];
int visited[MAX][MAX];
//전형적인 BFS

int BFS(int y, int x)
{
    for (int i =0; i<MAX; i++) for (int j = 0 ; j<MAX; j++) visited[i][j] =0;
    
    queue<pair<int, int>> q;
    
    int result = 0;
    q.push({y,x});
    
    visited[y][x] = 1;
    
    while (!q.empty()){
        
        int cy = q.front().first;
        int cx = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++){
            
            int ny  = cy + dy[i];
            int nx = cx + dx[i];
            
            result = max(result, visited[cy][cx]);
            
            if (0 <= ny && ny < L && 0 <= nx && nx < W){
                
                //중복되지 않았고 육지이면 큐에 넣는다
                
                if (map[ny][nx] == 'L' && visited[ny][nx] == 0){
                    
                    q.push({ny,nx});
                    visited[ny][nx] = visited[cy][cx] + 1;
                    
                }
                
            }
            
        }
    }
    //result는 칸 수, 경로는 1을 빼야한다

    return result - 1;
    
}

int main(){
     ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> L >> W;
    for (int i = 0; i < L; i++) cin >> map[i];
    
    int result = 0;
    
    //brute force로 보물 위치 모두 찾아본다
    
    for (int i = 0; i < L; i++) for (int j = 0; j < W; j++) if (map[i][j] == 'L') result = max(result, BFS(i, j));

    cout << result << endl;
    
    return 0;
    
}

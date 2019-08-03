//
//  main.cpp
//  BJ4963
//
//  Created by 소율 on 02/08/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX = 1<<6;
const int dx[] = {0,0,-1,1,1,-1,-1,1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};

int map[MAX][MAX], w, h,ans;
bool visited[MAX][MAX];

void dfs(int y,int x){
    visited[y][x] = true;
    
    for (int i =0; i<8; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx >= 0 && nx < w && ny >= 0 && ny < h){
            if(map[ny][nx] == 1 && !visited[ny][nx]) dfs(ny,nx);
        }
    }
}
int main(int argc, const char * argv[]) {
    
    while(1){
       ans=0;
        
        for (int i =0; i<MAX; i++) for (int j =0; j<MAX; j++) map[i][j] = 0 ,visited[i][j] = false;
        
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if(!visited[i][j] && map[i][j] == 1) {
                    ans++,dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
        
    }
}

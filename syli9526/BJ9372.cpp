//
//  main.cpp
//  BJ9372
//
//  Created by 소율 on 26/07/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,a,b;

int main(int argc, const char * argv[]) {
    // insert code here...
   
    scanf("%d",&t);
    
    while(t--){
        scanf("%d %d",&n,&m);
        for (int i = 0; i<m; i++) scanf("%d %d",&a,&b);
        printf("%d\n",n-1);
    }
}

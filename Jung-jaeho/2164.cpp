#include <iostream>
#include <deque>

using namespace std;

int main() {

    int n;
    int i;
    int front;
    scanf("%d",&n);
    deque<int> q;
    for(i=1; i<=n; i++){
        q.push_back(i);
    }

    while(q.size()>1){
        q.pop_front();
        if( q.size() == 1){
            break;
        }
        front = q.front();
        q.pop_front();
        q.push_back(front);
    }
    printf("%d",q.front());
    return 0;
}
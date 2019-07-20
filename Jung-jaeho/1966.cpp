#include <stdio.h>


int findMax(int queue[], int N, int front, int rear)
{
    int M = queue[front], index = 0;
    int i;
    for (i = front + 1; i <= rear; i++) {
        if (M < queue[i])
        {
            M = queue[i], index = i;
        }

    }
    return index;
}
int main()
{
    int tc;
    int N;
    int M;
    int queue[10000];
    int maxIndex;
    int front=0;
    int rear;
    int now=0;
    int i=0;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d", &N, &M);
        front=0;
        now=0;
        rear = N - 1;   //맨뒤값 주소
        for ( i = 0; i < N; i++)
            scanf("%d", &queue[i]); //큐
        while (front - 1 != M)
        {
            maxIndex = findMax(queue, N, front, rear);
            for ( i = front; i < maxIndex; i++)
            {
                queue[++rear] = queue[front++];
                M = (M == front - 1) ? rear : M;
            }
            front++;
            now++;
        }
        printf("%d\n", now);
    }
    return 0;
}

#include<stdio.h>

int main()
{   
    int T,N,a,b,x,cnt;
    int arr[100000][2];
	int i=0;
    scanf("%d", &T);

    while(T)
	{
        scanf("%d", &N);
        cnt=1;
        for(i=0;i<N;i++)
		{ 
            scanf("%d %d",&a,&b);
            arr[a-1][0]=a;
            arr[a-1][1]=b;
        }
        x=arr[0][1];

        for(i=1;i<N;i++)
		{ 
			//2번째부터 비교 
            if(x>arr[i][1])
			{
                x=arr[i][1];
                cnt+=1;
            }
        }
        printf("%d\n", cnt);
		T--;
    }
}
import java.util.*;
import java.util.StringTokenizer;

public class BJ1051{
	public static int result=0;
	public static int [][]arr;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		arr=new int [N][M];
		for(int i=0;i<N;i++)
		{
			String temp=sc.next();
			for(int j=0;j<M;j++)
			{
				char al=temp.charAt(j);
				arr[i][j]=((int)al-48);
			}
		}
		int index=Math.min(N,M);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				for(int k=0;k<index;k++)
				{
					if(i+k<N && j+k<M) {
						int temp1=arr[i][j];
						int temp2=arr[i+k][j];
						int temp3=arr[i][j+k];
						int temp4=arr[i+k][j+k];
						if(temp1==temp2&& temp1==temp3 && temp3==temp4 &&temp2==temp4 && temp1==temp4 && temp2==temp3)
						{
							result=Math.max(result, (k+1)*(k+1));
						}
					}
				}
			}
		}
		System.out.println(result);
	}
}


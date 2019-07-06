import java.util.*;
import java.util.StringTokenizer;

public class BJ2875{
	public static int max=0;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int K=sc.nextInt();
		
		int temp1=0;
		int temp2=K;
		int garN=N;
		int garM=M;
		int result=0;
		
		while(true)
		{
			if(temp2<0)
			{
				break;
			}
			garN=garN-temp1;
			garM=garM-temp2;
			int count=0;
			while(true)
			{
				if((garN-=2)>=0 &&(garM-=1)>=0)
				{
					count++;
				}
				else
				{
					break;
				}
			}	
			if(max<count)
			{
				max=count;
			}
			count=1;
			garN=N;
			garM=M;
			temp1++;
			temp2--;
		}
		
		System.out.println(max);
	}
}


import java.util.*;
import java.util.StringTokenizer;

public class BJ14717{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int totalCount=(18*17)/2;

		int number1=sc.nextInt();
		int number2=sc.nextInt();
		int count=0;
		if(number1!=number2)
		{
			int sum=number1+number2;
			int cri=sum%10;
			for(int i=0;i<cri;i++)
			{
				for(int j=1;j<=10;j++)
				{
					for(int k=1;k<=10;k++)
					{
						if((j+k)%10==i && j!=k)
						{
							if(j==number1 || j==number2 || k==number1 ||k==number2)
							{
								count++;
							}
							else {
								count+=2;
							}
						}
					}
				}
			}
			if(count==0)
			{
				System.out.format("%.3f\n",0.0);
			}
			else {
			double al=(double)count/(double)totalCount;
			System.out.format("%.3f\n", al);
			}
		}
		if(number1==number2)
		{
			int temp=totalCount-(10-number1);
			if(temp==totalCount)
			{
				System.out.format("%.3f\n",1.0);
			}
			else {
			double al= (double)temp/(double)totalCount;
			System.out.format("%.3f\n", al);
			}
		}
	}
}
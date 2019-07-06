import java.util.*;
import java.util.StringTokenizer;

public class BJ1946{
	public static int [] result;
	public static int [][] arr;
	public static int count=1;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int T=sc.nextInt();
		result=new int [T];
		for(int i=0;i<T;i++)
		{
			int N=sc.nextInt();
			arr=new int [N][2];
			for(int j=0;j<N;j++)
			{
				//둘다 순위..
				int temp1=sc.nextInt();
				int temp2=sc.nextInt();
				arr[j][0]=temp1;
				arr[j][1]=temp2;
			}
			Arrays.sort(arr, new Comparator<int []>() {
				public int compare(int arr1[],int arr2[]) {
					return Integer.compare(arr1[0],arr2[0]);
				}
			});
			
			int past=arr[0][1];
			for(int j=1;j<N;j++)
			{
				if(past>arr[j][1])
				{
					past=arr[j][1];
					count++;
				}
			}
			System.out.println(count);
			count=1;
		}
		
	}
}
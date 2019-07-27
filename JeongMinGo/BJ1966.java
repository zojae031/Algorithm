import java.util.*;
import java.util.StringTokenizer;

public class BJ1966 {
	public static int [] priority;
	public static boolean [] checked;
	public static int [] order;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number=sc.nextInt();
		for(int i=0;i<number;i++)
		{
			int N=sc.nextInt();
			int M=sc.nextInt();
			priority=new int [N];
			checked=new boolean [N]; 
			order= new int [N];
			Queue <Integer> queue =new LinkedList<Integer>();
			for(int j=0;j<N;j++)
			{
				queue.add(j);
				priority[j]=sc.nextInt();
			}
			
			int ak=1;//처음 시작 
			while(!queue.isEmpty())
			{
				int temp=queue.poll();//뽑아낸다
				int index=0;//처음시작
				boolean check=false;
				while(true)
				{
					if(index>=N) //escape section
					{
						break;
					}
					if(index==temp) //같은것끼리 비교할 필요 X
					{
						index++;
						continue;
					}
					if(checked[index]) //예제 3번과 같은경우 이미 방문한곳이라면 갈필요 X
					{
						index++;
						continue;
					}
					
					if(priority[temp]<priority[index]) //돌면서 하나라도 크면 조건 2에해당함
					{
						queue.add(temp);
						check=true;
						break;
					}
					index++;
				}
				if(check==false)
				{
					checked[temp]=true;
					order[temp]=ak++;
				}
			}
			System.out.println(order[M]);
		}
		
	}
}

import java.util.*;
import java.util.StringTokenizer;

public class BJ2164{
	public static long [] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number=sc.nextInt();
		Queue<Integer> queue = new LinkedList<Integer>();
		
		int count=1;
		for(int i=0;i<number;i++)
		{
			queue.offer(count);
			count++;
		}
		for(int i=0;i<number-1;i++)
		{
			queue.poll();
			int temp=queue.poll();
			queue.offer(temp);
		}
		while(!queue.isEmpty())
		{
			System.out.println(queue.poll());
		}
	}
}


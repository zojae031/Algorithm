import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BJ1707{
	public static boolean check=true;
	public static int number1=1;
	public static int number2=-1;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int T=sc.nextInt(); //테스트 케이스 
		ArrayList<ArrayList<Integer>> graph;
		int [] arr;
		for(int i=0;i<T;i++)
		{
			int V=sc.nextInt();//정점의 갯수 
			int E=sc.nextInt();//간선의 갯수 
			arr = new int[V+1];
			graph=new ArrayList<ArrayList<Integer>>();
			for(int j=0;j<V+1;j++)
			{
				graph.add(new ArrayList<Integer>());
			}
			for(int j=0;j<E;j++)
			{
				int x=sc.nextInt();
				int y=sc.nextInt();
				graph.get(x).add(y);
				graph.get(y).add(x);
			}
			for(int j=1;j<V+1;j++)
			{
				if(!check)
				{
					break;
				}
				if(arr[i]==0) {
					dfs(i,number1,arr,graph,V);
				}
			}
			System.out.println(check?"YES":"NO");
				
		}
	}
	private static void dfs(int i, int number, int[] arr, ArrayList<ArrayList<Integer>> graph, int v) {
	
		arr[i]=number; //해당되는 값 넣기 여기에서 색 구
		for(int k:graph.get(i))
		{
			if(arr[k]==number) {
				check=false;
				return;
			}
			if(arr[k]==0)
			{
				dfs(k,-number,arr,graph,v);
			}
		}
	}
}
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

//Spanning tree는 n개의 정점을 가지는 그래프의 최소 간선의 수는 (n-1)개이고, (n-1)개의 간선으로 
//연결되어 있다면 필연적으로 트리 형태가 되고 이를 spanning Tree라 한다.

public class BJ9372{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int number=sc.nextInt();
		for(int i=0;i<number;i++)
		{
			int N=sc.nextInt();
			int M=sc.nextInt();
			
			for(int j=0;j<M;j++)
			{
				int x=sc.nextInt();
				int y=sc.nextInt();
			}
			System.out.println(N-1);
		}
	}
}
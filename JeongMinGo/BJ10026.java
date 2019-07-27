import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.StringTokenizer;


public class BJ10026{
	public static int N;
	public static char [][] arr;
	public static char [][] arr1;
	public static boolean [][] visited;
	public static boolean [][] visited1;
	public static int [] dx= {0,1,0,-1};
	public static int [] dy= {1,0,-1,0};
	public static int count=0;
	public static int count1=0;
	public static void main(String[] args) throws Exception {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		arr =new char[N][N];
		visited=new boolean [N][N];
		arr1=new char[N][N];
		visited1=new boolean[N][N];
		for(int i=0;i<N;i++)
		{
			String temp=sc.next();
			for(int j=0;j<temp.length();j++)
			{
				arr[i][j]=temp.charAt(j);
				arr1[i][j]=arr[i][j];
			}
		}
		//적록색약이 아닌사람이 봣을대 count
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(visited[i][j]==false&& arr[i][j]=='R')
				{
					findR(i,j);
					count++;
				}
				else if(visited[i][j]==false && arr[i][j]=='G')
				{
					findG(i,j);
					count++;
				}
				else if(visited[i][j]==false && arr[i][j]=='B')
				{
					findB(i,j);
					count++;
				}
				//				print();
			}
		}
		//적록색약인 사람이 보았을때 count1++;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if((visited1[i][j]==false&& arr1[i][j]=='R')|| (arr1[i][j]=='G'&&visited1[i][j]==false))
				{
					findRG(i,j);
					count1++;
				}
				else if(visited1[i][j]==false && arr1[i][j]=='B')
				{
					findB1(i,j);
					count1++;
				}
			}
		}
		System.out.println(count+" "+count1);

	}
	private static void findB1(int startX, int startY) {
		int X=startX;
		int Y=startY;
		visited1[X][Y]=true;

		if(arr1[X][Y]=='B')
		{
			arr1[X][Y]='Z';
			for(int i=0;i<4;i++)
			{
				int newX=X+dx[i];
				int newY=Y+dy[i];

				if(newX>=0 && newY>=0 && newX<N &&newY <N)
				{
					if(arr1[newX][newY]=='B'&& visited1[newX][newY]==false)
					{
						findB1(newX,newY);
					}
				}
			}
		}

	}
	private static void findRG(int startX, int startY) {
		int X=startX;
		int Y=startY;
		visited1[X][Y]=true;

		if(arr1[X][Y]=='R'||arr1[X][Y]=='G')
		{
			arr1[X][Y]='Z';
			for(int i=0;i<4;i++)
			{
				int newX=X+dx[i];
				int newY=Y+dy[i];

				if(newX>=0 && newY>=0 && newX<N &&newY <N)
				{
					if((arr1[newX][newY]=='R'&& visited1[newX][newY]==false) || (arr1[newX][newY]=='G'&& visited1[newX][newY]==false))
					{
						findRG(newX,newY);
					}
				}
			}
		}

	}
	private static void findB(int startX, int startY) {
		int X=startX;
		int Y=startY;
		visited[X][Y]=true;

		if(arr[X][Y]=='B')
		{
			arr[X][Y]='Z';
			for(int i=0;i<4;i++)
			{
				int newX=X+dx[i];
				int newY=Y+dy[i];

				if(newX>=0 && newY>=0 && newX<N &&newY <N)
				{
					if(arr[newX][newY]=='B' && visited[newX][newY]==false)
					{
						findB(newX,newY);
					}
				}
			}
		}

	}
	private static void findG(int startX, int startY) {
		int X=startX;
		int Y=startY;
		visited[X][Y]=true;

		if(arr[X][Y]=='G')
		{
			arr[X][Y]='Z';
			for(int i=0;i<4;i++)
			{
				int newX=X+dx[i];
				int newY=Y+dy[i];

				if(newX>=0 && newY>=0 && newX<N &&newY <N)
				{
					if(arr[newX][newY]=='G' && visited[newX][newY]==false)
					{
						findG(newX,newY);
					}
				}
			}
		}

	}
	private static void findR(int startX, int startY) {
		int X=startX;
		int Y=startY;
		visited[X][Y]=true;

		if(arr[X][Y]=='R')
		{
			arr[X][Y]='Z';
			for(int i=0;i<4;i++)
			{
				int newX=X+dx[i];
				int newY=Y+dy[i];

				if(newX>=0 && newY>=0 && newX<N &&newY <N)
				{
					if(arr[newX][newY]=='R' && visited[newX][newY]==false)
					{
						findR(newX,newY);
					}
				}
			}
		}

	}
}
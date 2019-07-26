import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.StringTokenizer;

public class BJ5430{
	public static boolean check=false;
	public static boolean flag=false;
//	public static Deque<String> queue;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		int number=Integer.parseInt(br.readLine());
		for(int i=0;i<number;i++)
		{
			String temp=br.readLine();
			int len=Integer.parseInt(br.readLine());
			String al=br.readLine();
			String [] str = al.substring(1, al.length()-1).split(",");
			Deque <String>queue  = new ArrayDeque<String>();//dequeue생성
			for(int j=0;j<str.length;j++)//dequeue에 넣어준다 
			{
				if(str[j].equals(""))
				{
					continue;
				}
				queue.add(str[j]);
			}
			for(int j=0;j<temp.length();j++)
			{
				if(temp.charAt(j)=='R')
				{
					check=!check; //유동적으로 바뀌여야 되니깐 true --> false, false -->true
				}
				else
				{
					if(queue.isEmpty())
					{
						flag=true;
						break;
					}
					if(check==false)
					{
						queue.pollFirst();
					}
					else
					{
						queue.pollLast();
					}
				}
			}
			if(flag==true)
			{
				System.out.println("error");
				flag=false;
				check=false;
				continue;
			}
			else
			{
				System.out.print("[");
				int size=queue.size();
				for(int j=0;j<size;j++)
				{
					if(check==false)
					{
						if(queue.size()==1)
						{
							System.out.print(queue.peekFirst());
							queue.pollFirst();
						}
						else
						{
							System.out.print(queue.peekFirst()+",");
							queue.pollFirst();
						}
					}
					else
					{
						if(queue.size()==1)
						{
							System.out.print(queue.peekLast());
							queue.pollLast();
						}
						else
						{
							System.out.print(queue.peekLast()+",");
							queue.pollLast();
						}
					}
				}
				System.out.println("]");
				check=false;
				flag=false;
			}
		}
		br.close();
	}
}


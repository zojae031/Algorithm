import java.util.*;
import java.util.StringTokenizer;

public class BJ1541 {
		public static int [] number1;
		public static int [] number2;
		public static int [] number3;
		public static int sum1=0;
		public static int sum2=0;
		public static int sum3=0;
		public static void main(String[] args) {
			Scanner sc= new Scanner(System.in);
			String str = sc.next();
			String temp1="";
			String temp2="";
			int index=0;
			for(int i=0;i<str.length();i++)
			{
				if(str.charAt(i)=='-')
				{
					index=i;
					break;
				}
			}
			
			if(index==0)
			{
				String al[]=str.split("\\+");
				number3= new int[al.length];
				for(int i=0;i<al.length;i++)
				{
					number3[i]=Integer.parseInt(al[i]);
				}
				for(int i=0;i<number3.length;i++)
				{
					sum3+=number3[i];
				}
				System.out.println(sum3);
				return;
			}
			
			for(int i=0;i<index;i++)
			{
				temp1+=str.charAt(i);
			}
			String arr1[] = temp1.split("\\+|-");
			number1= new int [arr1.length];
			for(int i=0;i<number1.length;i++)
			{
				number1[i]=Integer.parseInt(arr1[i]);
			}
			
			
			for(int i=index+1;i<str.length();i++)
			{
				temp2+=str.charAt(i);
			}
			String arr2[] = temp2.split("\\+|-");
			number2= new int [arr2.length];
			for(int i=0;i<number2.length;i++)
			{
				number2[i]=Integer.parseInt(arr2[i]);
			}
			for(int i=0;i<number1.length;i++)
			{
				sum1+=number1[i];
			}
			for(int i=0;i<number2.length;i++)
			{
				sum2+=number2[i];
			}
			System.out.println(sum1-sum2);
		}
	}
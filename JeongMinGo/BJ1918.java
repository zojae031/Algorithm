import java.util.*;
import java.util.StringTokenizer;

public class BJ1918{
	public static boolean flag=false;
	public static int result=0;
	public static int [] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str=sc.next();

		Stack<Character> stack = new Stack<Character>();

		String result="";
		//스택에 있는 연산자가 더 크거나 같으면 pop push 

		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)>='A' && str.charAt(i)<='Z')//피연산자는 result에 그냥 더해줌
			{
				result+=str.charAt(i);
			}
			else
			{
				if(str.charAt(i)=='*' || str.charAt(i)=='/') //+ -보다 우선순위가 높은경우, 같은경우 * / 보다 높은경우 없음
				{
					while(!stack.isEmpty() && (stack.peek() =='*' || stack.peek()=='/'))
					{
						result+=stack.peek();
						stack.pop();
					}
					stack.push(str.charAt(i));
				}
				if(str.charAt(i)=='+'||str.charAt(i)=='-')
				{
					while(!stack.isEmpty() && stack.peek()!='(')  //( 아닐때 까지 돈다  + - 
					{
						result+=stack.peek();
						stack.pop();
					}
					stack.push(str.charAt(i));
				}
				if(str.charAt(i)=='(')//여는 괄호는 그냥 스택에 push 해준다.
				{
					stack.push(str.charAt(i));
				}
				if(str.charAt(i)==')')
				{
					while(!stack.isEmpty() && stack.peek()!='(') //여기에 if아니잖아...
					{
						result+=stack.peek();
						stack.pop();
					}
					stack.pop(); //여기 없으면 ( 계속 존재 무조건 pop해줘야함 
				}
			}
		}
		while(!stack.isEmpty())
		{
			result+=stack.peek();
			stack.pop();
		}
		System.out.println(result);
	}
}

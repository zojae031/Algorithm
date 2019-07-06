#include <iostream>
#include <stdio.h>


int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	//인턴이 있을때
	while (k) {
		if (n>=2*m) 
		{
			n--;
		}
		else if (n<2*m)
		{
			m--;
		}
		k--;
	}
	if (n >=2*m)
	{
		printf("%d\n",m);
	}
	else
	{
		printf("%d\n",n/2);
	}
	return 0;
}
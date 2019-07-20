#include <stdio.h>

int main() {
	char str[101], ans[101], s[101];
	int i, j, top = 0, a_top = 0;

	scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++) {
		switch (str[i])
		{
		case '+':
		case '-':
			for (j = top - 1; s[j] != '(' && j >= 0; j--)
				ans[a_top++] = s[j];
			top = j + 1;
			s[top++] = str[i];
			break;
		case '*':
		case '/':
			for (j = top - 1; s[j] != '(' && s[j] != '+' && s[j] != '-' && j >= 0; j--)
				ans[a_top++] = s[j];
			top = j + 1;
			s[top++] = str[i];
			break;
		case '(':
			s[top++] = str[i];
			break;
		case ')':
			for (j = top - 1; s[j] != '(' && j >= 0; j--)
				ans[a_top++] = s[j];
			top = j;
			break;
		default:
			ans[a_top++] = str[i];
			break;
		}
	}
	for (j = top - 1; s[j] != '(' && j >= 0; j--)
		ans[a_top++] = s[j];
	ans[a_top] = '\0';
	printf("%s", ans);

	return 0;
}
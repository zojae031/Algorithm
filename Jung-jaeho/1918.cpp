#include <stdio.h>
#include <string.h>

int main() {
    char s[101], st[101];
    int i=0;
    int t=0,len;
    scanf("%s",s);
    len=strlen(s);
    for( i = 0 ; i < len ; i++) {
        switch(s[i]) {
            case '(':
                st[++t]='(';
                break;
            case ')':
                while(t>0 && st[t]!='(') {
                    printf("%c",st[t]);
                    t--;
                }
                if(st[t] == '(')
                    t--;
                break;
            case '*':
                //강제 들여쓰기 ㅈ같네요..
            case '/':

                while(t>0 && st[t]!='+' && st[t] != '-' && st[t] != '(' )
                {
                    printf("%c", st[t]);
                    t--;
                }
                st[++t]=s[i];
                break;
            case '+':
            case '-':
                while(t>0 && st[t]!='(')
                {
                    printf("%c", st[t]);
                    t--;
                }
                st[++t]=s[i];
                break;
            default:
                printf("%c",s[i]);
                break;
        }
    }
    while(t>0) {
        printf("%c", st[t]);
        t--;
    }
    printf("\n");

    return 0;
}


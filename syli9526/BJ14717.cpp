#include <cstdio>

using namespace std;

const int CASE = 153;
int n1, n2, temp, cnt = 0, target;

int main() {


    scanf("%d %d", &n1, &n2);


    if (n1 == n2) {
        cnt = CASE - (10 - n1);
        printf("%.3f", (float)cnt / CASE);
    } else {
        target = (n1 + n2) % 10;
        for (int i = 1; i <= 10; i++) {
            for (int j = i + 1; j <= 10; ++j) {
                temp = i + j;
                if (temp % 10 < target) {
                    if (i == n1 || j == n2 || i == n2 || j == n1) cnt += 2;
                    else cnt += 4;
                }
            }
        }
        printf("%.3f", (float) cnt / CASE);

    }

}
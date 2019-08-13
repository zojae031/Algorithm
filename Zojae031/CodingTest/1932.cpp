#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, input, idx = 0;
	int cnt1=1, cnt2=2;
	int total = n * (n + 1) / 2;
	int arr[500] = { 0 };
	int dp[500] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i < total; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 1; i < total; i++) {
		dp[i] = max(dp[idx] + arr[i], dp[idx] + arr[i]);
	}

	printf("%d", *max_element(dp, dp + n));


	return 0;
}
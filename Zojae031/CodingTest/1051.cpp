#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int main() {


	int n, m;
	int **arr;
	scanf("%d %d", &n, &m);
	arr = (int**)calloc(n, sizeof(int*));
	getchar();
	//Input
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(m, sizeof(int));
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	//Algo
	int size = 0;
	int max = 0;
	int compare = m > n ? m : n;
	
	while (size < compare) {
		for (int j = 0; j < n - size; j++) {
			for (int i = 0; i < m - size; i++) {
				int value = arr[j][i];
				if (value == arr[j][i + size] && value == arr[j + size][i] && value == arr[j + size][i+size]) {
					max = (size + 1) * (size + 1);
				}
			}
		}
		size++;
	}
	printf("%d", max);
	//Free
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}
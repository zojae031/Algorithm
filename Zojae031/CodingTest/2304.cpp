#include<iostream>
using namespace std;

int main() {
	int **arr; //y ,x

	int *buf[2];
	int num, maxHeight = 0, maxLen = 0;
	int x, y;


	cin >> num;

	for (int i = 0; i < 2; i++)
		buf[i] = (int*)calloc(num, sizeof(int));

	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		if (maxHeight < y)maxHeight = y;
		if (maxLen < x)maxLen = x;

		buf[0][i] = x;
		buf[1][i] = y;
	}
	arr = (int**)calloc(maxHeight, sizeof(int*));

	for (int i = 0; i < maxHeight; i++) {
		arr[i] = (int*)calloc(maxLen, sizeof(int));
	}


	for (int i = 0; i < num; i++) {
		for (int j = 0; j < buf[1][i]; j++) {//높이만큼 돈다
			arr[j][buf[0][i] - 1] = 1;
		}
	}

	for (int i = 0; i < maxHeight; i++) {//y축
		for (int j = 0; j < maxLen; j++) { //x축
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << maxLen << endl;
	cout << maxHeight << endl;
	//for(int i=0 ; i<)

	return 0;
}
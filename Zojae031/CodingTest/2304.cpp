#include<iostream>
#include<stack>
using namespace std;

int main() {
	int **arr; //y ,x

	int *buf[2];
	int num, maxHeight = 0, maxLen = 0;
	int maxHeightIndex = 0;
	int x, y;
	int area=0;
	int xCnt = 0, yCnt = 0;
	cin >> num;
	
	
	
	for (int i = 0; i < 2; i++)
		buf[i] = (int*)calloc(num, sizeof(int));

	//입력을 버퍼에 저장하며 최고높이, 최고길이를 저장
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		if (maxHeight < y) {
			maxHeight = y;
			maxHeightIndex = x;
		}
		if (maxLen < x)maxLen = x;

		buf[0][i] = x;
		buf[1][i] = y;
	}
	arr = (int**)calloc(maxHeight+1, sizeof(int*));

	for (int i = 0; i < maxHeight+1; i++) {
		arr[i] = (int*)calloc(maxLen, sizeof(int));
	}

	// 버퍼에 저장된 값 생성된 배열에 입력
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < buf[1][i]; j++) {//높이만큼 돈다
			arr[j][buf[0][i] - 1] = 1;
		}
	}

	for (int i = 0; i < maxHeight+1; i++) {//y축
		for (int j = 0; j < maxLen; j++) { //x축
			cout << arr[i][j];
		}
		cout << endl;
	}


	stack<pair<int,int>> s;
	s.push(pair<int, int>(0, 0));
	int i = 0;
	int j = 0;
	
		while(j<=maxHeightIndex &&i<=maxHeight){
			if (arr[i][j] == 0) {
				
				pair<int, int>compare = s.top();
				if (i > compare.first) { //현재 높이가 스택에 있는애보다 크면 푸쉬
					s.push(pair<int,int>(i,j));
				}
				j++;
			}
			else {
				i++;
			}

		}
	
		while (true) {
			pair<int, int> data = s.top();
			s.pop();
			if (s.empty())break;
			int width = data.second - s.top().second;
			int height = s.top().first;
			area += width * height;

		}

		cout << area;



	return 0;
}
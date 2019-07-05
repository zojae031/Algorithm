#include<iostream>
#include<queue>
#include<string>
using namespace std;
#pragma warning (disable:4996)
int main() {
	queue<int> queue; // 0 <= channel <=500,000
	string str;
	char * result;
	int num;// 0 <= num <= 10
	int *button;
	int idx = 0, subIdx = 0;
	int nearbyButton=0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		queue.push(str[i]-'0');
	}

	scanf("%d", &num);
	button = (int*)malloc(num*sizeof(int));
	result = (char*)calloc(queue.size()+1 , sizeof(char));
	// Input
	for (int i = 0; i < num; i++) {
		scanf("%d", button+i);
	}


	// Algo
	while (!queue.empty()) {
		int r = queue.front();
		queue.pop();
		bool flag = false;
		for (int i = 0; i < num; i++) {
			if (r == button[i]) {//고장난 버튼인지 체크
				flag = true;
				break;
			}
		}
		if (flag) {//고장난 버튼이면 가까운 버튼 찾기
			int min = 10;
			while (idx <10) {//최단 버튼 찾기
				for (int i = 0; i < num; i++) {
					if (button[i] == idx) {
						idx++;
						i = -1;
					}
				}
				if ((min > abs(idx - r) && idx<10)) { //내가 눌러야하는 버튼중 가장 가까운 버튼 찾기
					min = abs(idx - r);
					nearbyButton = idx;
				}
				idx++;
			}
			idx = 0;
		}
		else nearbyButton = r;
		result[subIdx++] = nearbyButton + '0';
		result[subIdx] = '\0';
	}
	int totalCnt = str.size() + abs(atoi(str.c_str()) - atoi(result));
	if (abs(100 - atoi(str.c_str())) < totalCnt) {
		printf("%d", abs(100 - atoi(str.c_str())));
	}
	else {
		//str값 - result 에 들어있는값 
		printf("%d", totalCnt);
	}
	

	free(button);
	free(result);
	return 0;
}
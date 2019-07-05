#include<iostream>
#pragma warning(disable:4996)
using namespace std;
typedef struct vol
{
	int doc;
	int interview;
}Volunteer;

int main() {
	Volunteer **v;
	int *hireCount;
	int t;//1<=T<=20
	int *n; //1<=n<=100,000
	int idx, value;
	scanf("%d", &t);
	hireCount = (int*)calloc(t, sizeof(int));
	n = (int*)calloc(t, sizeof(int));

	v = (Volunteer**)calloc(t, sizeof(Volunteer*));
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
		v[i] = (Volunteer*)calloc(n[i], sizeof(Volunteer));
		hireCount[i] = n[i];
		for (int j = 0; j < n[i]; j++) {
			scanf("%d %d", &idx, &value);
			v[i][idx-1].doc = idx;
			v[i][idx-1].interview = value;
		}
	}

	//Algo
	for (int i = 0; i < t; i++) {//Test Case
		for (int j = n[i] - 1; j >= 0; j--) { //맨 뒤부터 돈다
			for (int k = j-1; k >= 0; k--) {
				if (v[i][j].interview > v[i][k].interview) //나보다 인터뷰 점수 높니?
				{
					hireCount[i]--;
					break;
				}
			}
		}
	}


	//Print
	for (int i = 0; i < t; i++) {
		printf("%d\n", hireCount[i]);
	}
	//Memory Free
	free(n);
	free(hireCount);

	for (int i = 0; i < t; i++) {
		free(v[i]);
	}
	free(v);


	return 0;
}
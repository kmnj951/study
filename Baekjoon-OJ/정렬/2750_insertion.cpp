#include <iostream>

using namespace std;

void insertion_sort(int * num, int size) {
	for(int i=1; i<size; ++i) {
		int base = num[i];
		int j;
		for(j=i-1; j>=0 && num[j]>base; --j) {
			num[j+1] = num[j];
		}
		num[j+1] = base;
	}
}

void print(int* num, int size) {
	for(int i=0; i<size; ++i)
		printf("%d ", num[i]);
	printf("\n");
}

int main(void) {
	int N;
	scanf("%d", &N);
	int num[N];
	for(int i=0; i<N; ++i) {
		scanf("%d", &num[i]);
	}
	
	insertion_sort(num, N);
	
	print(num, N);
	return 0;
}

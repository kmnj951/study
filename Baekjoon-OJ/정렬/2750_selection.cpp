#include <iostream>

using namespace std;

void selection_sort(int * num, int size) {
	for(int i=0; i<size-1; ++i) {
		int small = i;
		for(int j=i+1; j<size; ++j) {
			if( num[small] > num[j] )
				small = j;
		}
		swap(num[i], num[small]);
	}
}

void swap( int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
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
	
	selection_sort(num, N);
	
	print(num, N);
	return 0;
}

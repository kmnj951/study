#include <iostream>

using namespace std;

void bubble_sort(int * num, int size) {
	for(int i=size-1; i>0; --i) {
		for(int j=0; j<i; ++j) {
			if( num[j] > num[j+1] )
				swap(num[j], num[j+1]);
		}
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
	
	bubble_sort(num, N);
	
	print(num, N);
	return 0;
}

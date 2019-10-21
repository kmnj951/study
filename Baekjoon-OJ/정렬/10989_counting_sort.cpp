#include <iostream>

using namespace std;
/*
void stable_counting_sort(int *num, int size) {
	int count[10001] = {0};
	int *sort = new int[size];
	for (int i = 0; i < size; ++i)
		++count[num[i]];
	for (int i = 1; i < 10001; ++i)
		count[i] += count[i-1];
	for (int i = size-1; i >= 0; --i) 
		sort[--count[num[i]]] = num[i];
	for (int i = 0; i < size; ++i)
		num[i] = sort[i];
	delete[] sort;
}
*/
int main(void) {
	int count[10001] = {0};
	int min = 10000;
	int max = 0;
	int N;
	scanf("%d", &N);
	int n;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &n);
		++count[n];
		min = min < n ? min : n;
		max = max > n ? max : n;
	}
	
	for (int i = min; i <= max; ++i) 
		while (count[i] > 0) {
			printf("%d\n", i);
			--count[i];
		}
	return 0;
}

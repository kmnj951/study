#include <cstdio>

void sort_with_sorted(int *num, int beg1, int end1, int beg2, int end2);

void merge_sort(int *num, int begin, int end) {
	if (end - begin <= 1)
		return;
		
	int mid = (begin + end) / 2;
	merge_sort(num, begin, mid);
	merge_sort(num, mid, end);
	sort_with_sorted(num, begin, mid, mid, end);
}

void sort_with_sorted(int *num, int beg1, int end1, int beg2, int end2) {
	int *merge = new int[end1 + end2 - beg1 - beg2];
	int index = 0;
	int i, j;
	for (i = beg1, j = beg2; i < end1 && j < end2; ++index) {
		if (num[i] < num[j]) 
			merge[index] = num[i++];
		else 
			merge[index] = num[j++];
	}
	while (i < end1)
		merge[index++] = num[i++];
	while (j < end2)
		merge[index++] = num[j++];
	
	index = 0;
	for (int k = beg1; k < end1; ++k)
		num[k] = merge[index++];
	for (int k = beg2; k < end2; ++k)
		num[k] = merge[index++];
	delete[] merge;
}

int main(void) {
	int N;
	int num[1000000];
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &num[i]);
	
	merge_sort(num, 0, N);
	for (int i = 0; i < N; ++i)
		printf("%d\n", num[i]);
	return 0;
}

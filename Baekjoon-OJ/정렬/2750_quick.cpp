#include <iostream>

using namespace std;

int num[1000000];

int choose_pivot_index(int begin, int end);
void swap(int &a, int &b);

void quick_sort(int *num, int begin, int end) {
	if (end - begin <= 1)
		return;
	int pivot = choose_pivot_index(begin, end);
	int smaller = begin;
	int greater = end-1;
	int p_num = num[pivot];
	while (smaller < greater) {
		while (num[smaller] < p_num)
			++smaller;
		while (num[greater] > p_num)
			--greater;
		swap(num[smaller], num[greater]);
	}
	pivot = smaller;
	quick_sort(num, begin, pivot);
	quick_sort(num, pivot+1, end);
}

int choose_pivot_index(int begin, int end) {
	return (end+begin)/2;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	
	quick_sort(num, 0, N);
	for (int i = 0; i < N; ++i)
		cout << num[i] << endl;

	return 0;
}

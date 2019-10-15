#include <iostream>

using namespace std;

int num[1000000];

int choose_pivot_index(int begin, int end);
void copy(int *src, int *dst, int begin, int end);
//void print(int* num, int size);

void quick_sort(int * num, const int begin, const int end) {
	if (end - begin <= 1)
		return;
	int size = end - begin;
	int* next_num = new int[size];
	int greater = size-1;	// next
	int smaller = 0;	// next
	int pivot = choose_pivot_index(begin, end);
	for (int i = begin; i < end; ++i) {
		if (i != pivot) {
			if (num[i] > num[pivot])
				next_num[greater--] = num[i];
			else
				next_num[smaller++] = num[i];
		}
		//print(next_num,size);
	}
	next_num[smaller] = num[pivot];
	//cout << "(" << size << ") " << begin << "~" << end << " [" << smaller << "] " << next_num[smaller] << ": ";
	//print(next_num, size);
	//cout << endl;
	copy(next_num, num, begin, end);
	delete[] next_num;
	pivot = begin + smaller;
	//cout << "(" << size << ") " << begin << "~" << pivot << endl;
	quick_sort(num, begin, pivot);
	//cout << "(" << size << ") " << pivot+1 << "~" << end << endl;
	quick_sort(num, pivot+1, end);
}

int choose_pivot_index(int begin, int end) {
	return (end+begin)/2;
}

void copy(int *small_src, int *dst, int begin, int end) {
	for (int i = begin; i < end; ++i)
		dst[i] = small_src[i-begin];
}

/*void print(int* num, int size) {
	for (int i = 0; i < size; ++i)
		cout << num[i] << " ";
	cout << endl;
}*/

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

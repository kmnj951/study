#include <iostream>
#include <string>
#include <utility>

using namespace std;

void stable_counting_sort(pair<int, string> *member, int size) {
	int count[201] = {0};
	pair<int, string> *sort = new pair<int, string>[size];
	for (int i = 0; i < size; ++i)
		++count[member[i].first];
	for (int i = 2; i <= 200; ++i)
		count[i] += count[i-1];
	for (int i = size-1; i >= 0; --i)
		sort[--count[member[i].first]] = member[i];
	for (int i = 0; i < size; ++i)
		member[i] = sort[i];
	delete[] sort;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	pair<int, string> member[100000];
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> member[i].first >> member[i].second;
	
	stable_counting_sort(member, N);
	for (int i = 0; i < N; ++i) 
		cout << member[i].first << " " <<  member[i].second << "\n";
	return 0;
}

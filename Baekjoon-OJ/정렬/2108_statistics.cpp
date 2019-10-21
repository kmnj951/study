#include <iostream>
#include <cmath>

#define index(x) ((x) + 4000)

using namespace std;

int main(void) {
	int avg, median, mode, range;
	int count[8001] = {0};
	int sum = 0;
	int max_count = 0;
	int min = 4000;
	int max = -4000;
	int N;
	cin >> N;	
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		++count[index(n)];
		sum += n;
		min = min < n ? min : n;
		max = max > n ? max : n;
	}
	avg = round(double(sum)/N);
	range = max-min;
	
	// N % 2 == 1
	int middle = (N+1)/2;
	int accum = 0;
	int mode_check = 0;
	for (int n = min; n <= max; ++n) {
		if (accum < middle)
			median = n;
		if (max_count < count[index(n)]) {
			max_count = count[index(n)];
			mode = n;
			mode_check = 1;
		}
		else if (max_count == count[index(n)] && mode_check < 2) {
			max_count = count[index(n)];
			mode = n;
			++mode_check;
		}
		accum += count[index(n)];
	}
		
	cout << avg << "\n"
		<< median << "\n"
		<< mode << "\n"
		<< range;
		
	return 0;
}

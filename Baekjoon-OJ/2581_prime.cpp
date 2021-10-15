#include <iostream>
#include <cmath>

using namespace std;

int main() {
	bool not_prime[10001] = {true, true};
	int end = floor(sqrt(10000));	// 100
	for (int i = 2; i <= end; ++i) {
		if (!not_prime[i])
			for (int j = i * 2; j <= 10000; j += i) {
				not_prime[j] = true;
			}
	}

	int M, N;
	int min = -1;
	int sum = 0;
	cin >> M >> N;
	for (int n = M; n <= N; ++n) {
		if (!not_prime[n]) {
			if (sum == 0)
				min = n;
			sum += n;
		}
			
	}
	if (sum != 0)
		cout << sum << "\n";
	cout << min;
	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	bool not_prime[1001] = {true, true};
	int end = floor(sqrt(1000));
	for (int i = 2; i <= end; ++i) {
		if (!not_prime[i])
			for (int j = i * 2; j <= 1000; j += i) {
				not_prime[j] = true;
			}
	}

	int N;
	int n;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> n;
		if (!not_prime[n])
			++count;
	}
	cout << count;
	return 0;
}

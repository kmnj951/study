#include <iostream>

using namespace std;

int main() {
	const int max = 1000000;
	bool not_prime[max + 1] = {true, true};
	int end = 1000;
	for (int i = 2; i <= end; ++i) {
		if (!not_prime[i])
			for (int n = 2 * i; n <= max; n += i)
				not_prime[n] = true; 
	}
	
	int M, N;
	cin >> M >> N;
	for (int n = M; n <= N; ++n) {
		if (!not_prime[n])
			cout << n << "\n";
	}
	return 0;
}

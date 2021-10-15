#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int n;
	for (n = 2; n * n <= N; ++n) {
		if (N % n == 0) {
			cout << n << "\n";
			N /= n;
			--n;
		}
	}
	if (N > 1)
		cout << N << "\n";
	return 0;
}

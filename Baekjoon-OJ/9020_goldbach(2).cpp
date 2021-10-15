#include <iostream>

using namespace std;

int main(void) {
	bool not_prime[10001] = {true, true};
	for (int i = 0; i <=100; ++i) {
		if (!not_prime[i]) {
			for (int n = 2 * i; n <= 10000; n += i) {
				not_prime[n] = true;
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	int n;
	for (int t = 0; t < T; ++t) {
		scanf("%d", &n);
		for (int part = n/2; part > 1; --part) {
			if (!not_prime[part]) {
				int pair = n - part;
				if (!not_prime[pair]) {
					printf("%d %d\n", part, pair);
					break;
				}
			}				
		}
	}
	return 0;
}

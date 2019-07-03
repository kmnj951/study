#include <iostream>
#include <cmath>

using namespace std;

bool check_prime(int num) {
	static char prime[10001] = {1,1,1,0}; 	// 1: prime, 0: ?, -1: composite
	if( prime[num] == 1 )
		return true;
	if( prime[num] == -1)
		return false;
	for(int i=2; i<=sqrt(num); ++i) {
		if( prime[i] == 0 )
			check_prime(i);
		if ( prime[i] > 0 && num%i == 0) {
			prime[num] = -1;
			return false;
		}
			
	}
	prime[num] = 1;
	return true;
}

int main(void) {
	int T;
	scanf("%d", &T);
	int n;
	for(int t=0; t<T; ++t) {
		scanf("%d", &n);
		for(int part=n/2; part>1; --part) {
			if( check_prime(part) ) {
				int pair = n - part;
				if( check_prime(pair) ) {
					printf("%d %d\n", part, pair);
					break;
				}
			}				
		}
	}
	return 0;
}

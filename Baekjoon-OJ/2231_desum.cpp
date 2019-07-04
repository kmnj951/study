#include <iostream>

using namespace std;


int main(void) {
	int N;
	scanf("%d", &N);
	
	for(int i=N-54; i<N; ++i) {
		int sum = i;
		for(int j=i; j>0; j/=10)
			sum += j%10;
		if( sum == N ) {
			printf("%d", i);
			return 0;
		}	
	}
	
	printf("%d", 0);	
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	int card[N];
	for(int i=0; i<N; ++i)
		scanf("%d", &card[i]);
	sort(card, card+N);
	
	int s_max = 0;
	for(int i=N-1; i>=2; --i) {
		int sum = card[i];
		for(int j=i-1; j>=1; --j) {
			sum += card[j];
			for(int k=j-1; k>=0; --k) {
				if( sum + card[k]> s_max ) {
					if (sum + card[k]<=M )
						s_max = sum + card[k];
				}
				else
					break;
			}
			sum -= card[j];	
		}
	}
	printf("%d", s_max);
	return 0;
}

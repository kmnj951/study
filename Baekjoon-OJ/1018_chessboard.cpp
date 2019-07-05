#include <iostream>

using namespace std;

int main(void) {
	//freopen("1018.txt", "r", stdin);
	int N, M;
	scanf("%d%d", &N, &M);
	
	bool board[N][M];
	for(int i=0; i<N; ++i) {
		int ch;
		for(int j=0; j<M; ++j) {
			scanf(" %c", &ch);
			board[i][j] = (ch == 'B');
		}
	}
	bool board_default[8][8];
	for(int i=0; i<8; ++i) {
		for(int j=0; j<8; ++j) {
			if( ((i+j)<<31) != 0 )	// (i+j)%2 != 0
				board_default[i][j] = true;
			else 
				board_default[i][j] = false;
		}
	}

	int diff_min = 64;
	for(int i=8; i<=N; ++i) {
		for(int j=8; j<=M; ++j) {	
			int diff[2] = {0};		
			for(int k=i-8, kk=0; k<i; ++k, ++kk)	// do I need to search all?
				for(int l=j-8, ll=0; l<j; ++l, ++ll) {
					if( board[k][l] == board_default[kk][ll] )
						diff[0]++;
					else
						diff[1]++;
				}
			diff_min = (diff[0]<diff_min) ? diff[0] : diff_min;
			diff_min = (diff[1]<diff_min) ? diff[1] : diff_min;
		}
	}	
	printf("%d", diff_min);
	
	return 0;
}

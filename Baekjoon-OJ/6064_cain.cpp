#include <iostream>

using namespace std;

/*
ū�� : M
������ : N
���� : x-y(mod N)
     ������ N-M�� �������� ( �ϳ��� M�� �ݺ� ) 
0 0 0 0 ...M��... 0 0
N-M N-M ...M��... N-M N-M
*/

int difference(int minuend, int subtrahend, int mod) {
	int d = (minuend-subtrahend)%mod;
	d = d>=0? d : d+mod;
	return d; 
}

int sequence(int small, int large, int se, int le) {
	int com_diff = difference(small,large,small);	
	int diff = difference(le,se,small);
	if( com_diff == 0 ) { // small�� large�� ��� 
		if( diff == 0 )
			return le;
		else
			return -1;
	}
	int n = 0;
	int i;  
	for(i=0; n != diff; ++i) {
		n = (n + com_diff)%small;
		if( n == 0 )
			return -1;
	}
	return large*i + le;
}

int main(void) {
	int num;
	cin >> num;
	int M, N, x, y;
	for( int i=0; i<num; ++i) {
		cin >> M >> N;
		cin >> x >> y;
		if ( M <= N )
			cout << sequence ( M, N, x, y ) << "\n";
		else
			cout << sequence ( N, M, y, x ) << "\n";		
	}
	return 0;
}

#include <iostream>

using namespace std;

int next_num(int num) {
	int n = num;
	while(n>0) {
		num += n%10;
		n /=10;
	}
	return num;
}

int main(void) {
	bool num[10001] = {0};
	for(int i=1; i<=10000; ++i) {
		if( !num[i] ) {
			printf("%d\n", i);
//			int n = i;
//			while( ( n = next_num(n) ) <= 10000) {
//				if( num[n] )
//					break;
//				num[n] = true;
//			}
		}
		int next = i;
		for(int n=next; n>0; n/=10)
			next += n%10;
		if( next <= 10000 )
			num[next] = true;
	}
	return 0;
}

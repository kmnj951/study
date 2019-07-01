#include <iostream>

using namespace std;

bool space_num(int num, int col) {
	int k = col;
	for(int i=1; i<num; ++i) {
		k /= 3;
	}
	if( k%3 == 1) {
		cout << " ";
		return true;
	}
	return false;
}

int main(void) {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			bool print = false;		
			int k = 1;
			for(int row = i; row>0 && !print; row /= 3) {
				if( row%3 == 1 )
					print = space_num(k, j);
				++k;					
			} 
			if( !print )
				cout << "*";
		}
		cout << "\n";
	}
	return 0;
}

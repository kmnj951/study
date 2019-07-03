#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int N;
	int x[2];
	int y[2];
	int r[2];
	cin >> N;
	for(int n=0; n<N; ++n) {
		for(int i=0; i<2; ++i)
			cin >> x[i] >> y[i] >> r[i];
		double distance = sqrt((x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]) );
		int r_add = r[0]+r[1];
		int r_sub = r[0]-r[1];
		r_sub = r_sub>=0? r_sub : -r_sub;
		if( distance == 0 ) {
			if(r[0] == r[1])	
				cout << -1;
			else
				cout << 0;
		}
		else if( distance > r_add || distance < r_sub)
			cout << 0;
		else if( distance == r_add || distance == r_sub)
			cout << 1;
		else
			cout << 2;
		cout << "\n";
	}
	return 0;
}

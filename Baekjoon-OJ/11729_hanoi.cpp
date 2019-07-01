#include <iostream>
#include <sstream>

using namespace std;

stringstream ss;

int tower(int num, int src, int dst) {	
	if( num == 1 ) {
		ss << src << " " << dst << "\n";
		return 1;
	}
	int count = 0;
	int pre_dst = 6-src-dst;
	count += tower(num-1, src, pre_dst);
	ss << src << " " << dst << "\n";
	count += tower(num-1, pre_dst, dst);
	return ++count;
}

int main(void) {
	int N;
	cin >> N;
	cout << tower(N,1,3) << "\n";
	cout << ss.str();
	return 0;
}

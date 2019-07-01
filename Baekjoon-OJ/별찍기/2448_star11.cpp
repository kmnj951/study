#include <iostream>

using namespace std;

class StarTriangle {
private:
	const int size;
	char stars[3][6] = {"  *  ", " * * ", "*****"};
	char empty[6] = "     ";
	void print_star(int level);
	void print_sibling(int gab, int level);
	static bool in_2( int check, int full );
public:
	StarTriangle(int _size) : size(_size) {}
	void print();
};

void StarTriangle::print() {
	for(int i=0; i<size; ++i)
		print_star(i);
}

void StarTriangle::print_star(int level) {
	int indent = (size-level-1)*3;
	for( int k=0; k<3; ++k) {
		for(int i=0; i<indent; ++i)
			printf(" ");
		printf("%s", stars[k]);	
		print_sibling(k,level);
		for(int i=0; i<indent; ++i)
			printf(" ");
		printf("\n");
	}
}

void StarTriangle::print_sibling(int sub_level, int level) {
//101 : 0 1 100 101
//111 : 0 1 10 11 100 101 110 111
	for(int i=1; i<=level; ++i) {
		printf(" ");
		if( in_2(i,level) )
			printf("%s", stars[sub_level]);
		else
			printf("%s", empty);
	}
}

bool StarTriangle::in_2( int check, int full ) {
	while( full > 0 ) {
		if( check%2 == 1 && full%2 == 0 )
			return false;
		check >>= 1;
		full >>= 1;
	}
	return true;
}

int main(void) {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);

	int N;
	cin >> N;	// 3 * 2^k
	N /= 3;
	StarTriangle s(N);
	s.print();
	
	return 0;
}

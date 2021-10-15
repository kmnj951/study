#include <iostream>

class QPos {
private:
	int x;
	int y;
public:
	QPos(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	//QPos(const QPos& pos) : x(pos.x), y(pos.y) {} default
	bool kill(const QPos& pos) {
		if (x == pos.x || y == pos.y || x+y == pos.x+pos.y || x-y == pos.x-pos.y) 
			return true;
		return false;
	}
};

int add_queen(QPos* queen, int N, int depth) {
	int cases = 0;
	if (N == depth)
		return 1;
	for (int y = 0; y < N; ++y) {
		QPos pos(depth, y);
		int i;
		for (i = 0; i < depth && !pos.kill(queen[i]); ++i)
			;
		if (i == depth) {
			queen[depth] = pos;
			cases += add_queen(queen, N, depth + 1);
		}
			
	}
	return cases;
}

int main() {
	int N;
	QPos queen[15]= {};
	std::cin >> N;	
	std::cout << add_queen(queen, N, 0);	
	return 0;
}

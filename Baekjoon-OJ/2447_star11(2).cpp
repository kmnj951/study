#include <iostream>

using namespace std;

bool pattern[2187][2187];

struct point {
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y) {};
	point operator+(const point& p) {
		return point(x+p.x, y+p.y);
	}
}; 

void make_hole(bool land[][2187], point begin, int width) {	// width = 3^k
	const static bool hole[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	if (width%3 == 0) {
		int unit = width / 3;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (hole[i][j]) {
					for (int x = 0; x < unit; ++x) 
						for (int y = 0; y < unit; ++y) 
							land[x+unit+begin.x][y+unit+begin.y] = true;
				}
				else {
					make_hole(land, begin + point(unit*i, unit*j), unit);
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);	// independent C++ buffer
	cin.tie(NULL);	// not flush when using cin
	int N;
	cin >> N;
	make_hole(pattern, point(0, 0), N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (pattern[i][j])
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}

	return 0;
}

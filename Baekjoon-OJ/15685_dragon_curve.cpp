#include <iostream>
#include <vector>

using namespace std;

struct point {
public:
	int x;
	int y;
public:
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	bool check_range() {
		return !(x < 0 || x > 100 || y < 0 || y > 100);
	}
	friend istream& operator>>(istream& in, point& p) {
		return in >> p.x >> p.y;
	}
	friend ostream& operator<<(ostream& out, const point& p) {
		return out << "(" << p.x << ", " << p.y << ")";
	}
};


void clockwise90(vector<point>& points, bool curve[101][101]) {
	int size = points.size();
	point end_point = points[size-1];
	point p;
	for (int i = size-2; i >= 0; --i) {
		int diff_x = points[i].x - end_point.x;
		int diff_y = points[i].y - end_point.y;
		int tmp = diff_x;
		diff_x = -diff_y;
		diff_y = tmp;
		p.x = end_point.x + diff_x;
		p.y = end_point.y + diff_y;
		points.push_back(p);
		if (!p.check_range())
			return;
		curve[p.x][p.y] = true;
	}
}

int main(void) {
	bool curve[101][101] ={{0}};
	int N;
	vector<point> points;
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		point p;
		int dir, time;		
		cin >> p >> dir >> time;
		
		points.clear();
		curve[p.x][p.y] = true;
		points.push_back(p);
		switch (dir) {
			case 0:
				p.x += 1;
				break;
			case 1:
				p.y -= 1;
				break;
			case 2:
				p.x -= 1;
				break;
			case 3:
				p.y += 1;
				break;
		}
		points.push_back(p);
		if (p.check_range())
			curve[p.x][p.y] = true;
		for (int t = 0; t < time && p.check_range(); ++t) {
			clockwise90(points, curve);	
			p = points[points.size()-1];
		}	
	}
	
	// curve area
	int area = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (curve[i][j] && curve[i][j+1] && curve[i+1][j] && curve[i+1][j+1])
				++area;
	
	cout << area;
	return 0;
}

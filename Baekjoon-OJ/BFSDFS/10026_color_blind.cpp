#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class color {
private:
	char color1;
	char color2;
public:
	color(char _color1 = 0, char _color2 = 0): color1(_color1), color2(_color2) {}
	bool operator==(char c) {
		return color1 == c || color2 == c;
	}
	bool operator==(const color& c) const {
		return color1 == c.color1 && color2 == c.color2;
	}
};

void look(bool color_blind, const int N, 
	char picture[][100], bool focus[][100], const pair<int, int>& from)
{
	int dir[4] = {0, 0, -1, 1};
	char c = picture[from.first][from.second];
	color comp;
	if (color_blind && (c == 'R' || c == 'G')) {
		comp = color('R', 'G');
	}
	else {
		comp = color(c);
	}
	queue<pair<int, int> > bfs_q;
	bfs_q.push(from);
	
	while (!bfs_q.empty()) {
		pair<int, int> x_y = bfs_q.front();
		int x = x_y.first;
		int y = x_y.second;
		bfs_q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir[i];
			int next_y = y + dir[3-i];
			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N 
				&& !focus[next_x][next_y] && comp == picture[next_x][next_y]) {
				focus[next_x][next_y] = true;
				bfs_q.push(make_pair(next_x, next_y));
				
			}
		}
	}
} 

void normal_look(const int N, char picture[][100], bool focus[][100], const pair<int, int>& from) {
	look(false, N, picture, focus, from);
} 

void color_blind_look(const int N, char picture[][100], bool focus[][100], const pair<int, int>& from) {
	look(true, N, picture, focus, from);
} 

int main(void) {
	int N;
	char picture[100][100];
	bool my_look[100][100] = {{0}};
	bool color_blind[100][100] = {{0}};
	int answer[2] = {0};
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> picture[i][j];
	
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (!my_look[i][j]) {
				normal_look(N, picture, my_look, make_pair(i, j));
				++answer[0];
			}
			if (!color_blind[i][j]) {
				color_blind_look(N, picture, color_blind, make_pair(i, j));
				++answer[1];
			}
		}
			
	cout << answer[0] << " " << answer[1];
	return 0;
}

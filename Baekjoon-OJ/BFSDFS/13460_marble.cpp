#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

struct loc {
	int x;
	int y;
	
	loc(int _x = 0, int _y = 0): x(_x), y(_y) {}
	loc(const loc& location): x(location.x), y(location.y) {}
	bool operator==(const loc& location) const {
		return x == location.x && y == location.y;
	}
	bool operator!=(const loc& location) const {
		return !(*this==location);
	}
	friend ostream& operator<<(ostream& os, const loc& location) {
		return os << location.x << " " << location.y;
	}
};

enum dir {
	STOP, LEFT, RIGHT, UP, DOWN
};

loc find_end(char board[][10], const loc& start, dir direction, loc other_marble) {
	loc step = {0, 0};
	loc cur = start;
	
	if (board[start.x][start.y] != '.'|| start == other_marble)
		return start;
		
	switch(direction) {
		case LEFT:
			step.y = -1;
			break;
		case RIGHT:
			step.y = 1;
			break;
		case UP:
			step.x = -1;
			break;
		case DOWN:
			step.x = 1;
			break;
		default:
			return cur;
	}
	while (board[cur.x][cur.y] == '.') {
		if (cur == other_marble) {	// 다른 구슬도 움직여보기 
			loc other_tmp = find_end(board, other_marble, direction, {-1,-1});
			if(other_tmp != other_marble)
				other_marble = other_tmp;
			else
				break;
		}
		cur.x += step.x;
		cur.y += step.y;
	}
	if (board[cur.x][cur.y] == 'O') 
		return cur;
	
	cur.x -= step.x;
	cur.y -= step.y;
	return cur;
}

int red_escape(char board[][10], int N, int M) {
	loc red, blue, goal;
	int depth = 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 'R') {
				red = {i, j};
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue = {i, j};
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') {
				goal = {i, j};
			}
		}
			
	queue<pair<loc, int> > bfs_red;
	queue<loc> bfs_blue;
	bfs_red.push(make_pair(red, depth));
	bfs_blue.push(blue);
	
	while (!bfs_red.empty()) {
		loc red_next, blue_next;
		dir four_dir[4] = {LEFT, RIGHT, UP, DOWN};
		
		pair<loc, int> red_depth = bfs_red.front();
		red = red_depth.first;
		depth = red_depth.second;
		blue = bfs_blue.front();
		bfs_red.pop();
		bfs_blue.pop();
		
		if (depth > 10)
			break;
		
		for (int i = 0; i < 4; ++i) {
			dir cur_dir = four_dir[i];
			red_next = find_end(board, red, cur_dir, blue);
			blue_next = find_end(board, blue, cur_dir, red);
			// or : 1. priority --> decision order red_next, blue_next : simple find_end 
			//      2. dfs and save min depth
			if ((red_next != red || blue_next != blue) && blue_next != goal) {
				if (red_next == goal) {
					loc last_blue = find_end(board, blue, cur_dir, {-1, -1});
					if (last_blue != goal)
						return depth;
				}
				else {
					bfs_red.push(make_pair(red_next, depth+1));
					bfs_blue.push(blue_next);	
					//cout << red_next << " : " << blue_next << endl;
				}
			}
		}	
	}
	return -1;	
}

int main(void) {
	int N, M;
	char board[10][10];
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
			
	cout << red_escape(board, N, M);
	return 0;
}

#include <iostream>

using namespace std;

typedef int move_function(int[][20], int);
int move_left(int board[][20], int N);
int move_right(int board[][20], int N);
int move_up(int board[][20], int N);
int move_down(int board[][20], int N);

void copy_board(int src[][20], int dst[][20], int N) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			dst[i][j] = src[i][j];
}

int move(int board[][20], int N, int dir) {
	static move_function* move_dir[4] = {&move_left, &move_right, &move_up, &move_down};
	if (dir < 0 || dir >= 4)
		return -1;
	return move_dir[dir](board,N);
	
}

int move_left(int board[][20], int N) {
	int max = 0;
	for (int line = 0; line < N; ++line) {
		int cur = 0;
		int prev = 0;
		for (int i = 0; i < N; ++i) {
			if (board[line][i] > 0) {
				if (board[line][i] == prev) {
					--cur;
					board[line][cur++] = board[line][i]*2;
					prev = 0;
				}
				else {
					board[line][cur++] = board[line][i];
					prev = board[line][i];
				}
			}
		} 
		for (int i = 0; i < cur; ++i)
			max = max > board[line][i] ? max : board[line][i];
		for (int i = cur; i < N; ++i) {
			board[line][i] = 0;
		}
	}
	return max;
}

int move_right(int board[][20], int N) {
	int max = 0;
	for (int line = 0; line < N; ++line) {
		int cur = N-1;
		int prev = 0;
		for (int i = N-1; i >= 0; --i) {
			if (board[line][i] > 0) {
				if (board[line][i] == prev) {
					++cur;
					board[line][cur--] = board[line][i]*2;
					prev = 0;
				}
				else {
					board[line][cur--] = board[line][i];
					prev = board[line][i];
				}
			}
		} 
		for (int i = N-1; i > cur; --i)
			max = max > board[line][i] ? max : board[line][i];
		for (int i = cur; i >= 0; --i) {
			board[line][i] = 0;
		}
	}
	return max;
}

int move_up(int board[][20], int N) {
	int max = 0;
	for (int line = 0; line < N; ++line) {
		int cur = 0;
		int prev = 0;
		for (int i = 0; i < N; ++i) {
			if (board[i][line] > 0) {
				if (board[i][line] == prev) {
					--cur;
					board[cur++][line] = board[i][line]*2;
					prev = 0;
				}
				else {
					board[cur++][line] = board[i][line];
					prev = board[i][line];
				}
					
			}
		} 
		for (int i = 0; i < cur; ++i)
			max = max > board[i][line] ? max : board[i][line];
		for (int i = cur; i < N; ++i) {
			board[i][line] = 0;
		}
	}
	return max;
}

int move_down(int board[][20], int N) {
	int max = 0;
	for (int line = 0; line < N; ++line) {
		int cur = N-1;
		int prev = 0;
		for (int i = N-1; i >= 0; --i) {
			if (board[i][line] > 0) {
				if (board[i][line] == prev) {
					++cur;
					board[cur--][line] = board[i][line]*2;
					prev = 0;
				}
				else {
					board[cur--][line] = board[i][line];
					prev = board[i][line];
				}
			}
		} 
		for (int i = N-1; i > cur; --i)
			max = max > board[i][line] ? max : board[i][line];
		for (int i = cur; i >= 0; --i) {
			board[i][line] = 0;
		}
	}
	return max;
}

/*void print(int a[][20], int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N ; ++j)
			cout << a[i][j] << " " ;
		cout << endl;
	}
	cout << endl;
}*/

int max_block_num(int board[][20], int N, int depth, int pre_dir) {
	static int max = 0;
	int block;
	int next_board[20][20];
	
	for (int dir = 0; dir < 4; ++dir) {
		if (dir != pre_dir) {
			//cout << depth << ": " << i << endl;
			copy_board(board, next_board, N);
			block = move(next_board, N, dir);
			//print(next_board, N);
			if (depth == 5) {
				if (max < block)
					max = block;
			}
			else if(max>>(5-depth) <= block)
				max_block_num(next_board, N, depth+1, dir);
		}
	}
	return max;
}

int main(void) {
	int N;
	int board[20][20];
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
			
	cout << max_block_num(board, N, 1, -1);
	return 0;
}

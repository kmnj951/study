#include <iostream>
#include <utility>

using namespace std;

int longest_way(char board[][20], bool check_alphabet[26], pair<int, int> pos, int R, int C) {
	static const int dir[4] = {1, -1, 0, 0};
	int longest_len = 0;
	char cur_alphabet = board[pos.first][pos.second];
	check_alphabet[cur_alphabet - 'A'] = true;
	for (int i = 0; i < 4; ++i) {
		int x = pos.first + dir[i];
		int y = pos.second + dir[3-i];
		if (x >= 0 && y >= 0 && x < R && y < C && !check_alphabet[board[x][y] - 'A']) {
			int len = longest_way(board, check_alphabet, make_pair(x,y), R, C);
			longest_len = len > longest_len ? len : longest_len;
		}
	}
	check_alphabet[cur_alphabet - 'A'] = false;
	return longest_len + 1;
}

int main(void) {
	char board[20][20];
	int R, C;
	bool alphabet[26] = {0};
	int answer;
	
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> board[r][c];
		}
	}
	
	answer = longest_way(board, alphabet, make_pair(0,0), R, C);
	cout << answer;
	return 0;
}

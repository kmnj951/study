#include <iostream>

class Sudoku {
private:
	int board[9][9];	
private:
	bool check_line(int row, int col, int value);
	bool check_group(int row, int col, int value);
public:
	bool solve_from(int row, int col);
	friend std::istream& operator>>(std::istream& is, Sudoku& sudoku);
	friend std::ostream& operator<<(std::ostream& is, const Sudoku& sudoku);
};

bool Sudoku::check_line(int row, int col, int value) {
	int i;
	for (i = 0; i < 9 && board[row][i] != value; ++i)
		;
	if (i < 9)
		return false;
	for (i = 0; i < 9 && board[i][col] != value; ++i)
		;
	if (i < 9)
		return false;
	return true;
}

bool Sudoku::check_group(int row, int col, int value) {
	int group_row = row / 3 * 3;
	int group_col = col / 3 * 3;
	int r, c;
	for (r = group_row; r < group_row + 3; ++r) {
		for (c = group_col; c < group_col + 3 && board[r][c] != value; ++c)
			;
		if (c < group_col + 3)
			break;
	}
	if (r < group_row + 3)
		return false;
	return true;
}

bool Sudoku::solve_from(int row, int col) {
	int* p_board = (int*)board;
	for (int i = row*9 + col; i < 81; ++i) {
		if (p_board[i] == 0) {
			int r = i / 9;
			int c = i % 9;
			for (int n = 1; n <= 9; ++n) {
				if (check_line(r, c, n) && check_group(r, c, n)) {
					board[r][c] = n;
					if (solve_from(r, c))
						return true;
					board[r][c] = 0;
				}
			}
			return false;	
		}
	}
	return true;
}

std::istream& operator>>(std::istream& is, Sudoku& sudoku) {
	for (int r = 0; r < 9; ++r) {
		for (int c = 0; c < 9; ++c) {
			is >> sudoku.board[r][c];
		}
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku) {
	for (int r = 0; r < 9; ++r) {
		for (int c = 0; c < 9; ++c) {
			os << sudoku.board[r][c] << " ";
		}
		os << "\n";
	}
	return os;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Sudoku sdk;
	std::cin >> sdk;
	sdk.solve_from(0, 0);
	std::cout << sdk;
	return 0;
}

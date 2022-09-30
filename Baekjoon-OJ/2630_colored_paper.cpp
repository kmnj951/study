#include <iostream>
#include <vector>

template <typename T,typename U>                                                   
std::pair<T,U>& operator+=(std::pair<T,U>& l,const std::pair<T,U>& r) {
	l.first += r.first;
	l.second += r.second;
    return l;                                    
}

char check_full(const std::vector<std::vector<char>>& paper, int r_beg, int c_beg, int r_end, int c_end) {
	char cmp = paper[r_beg][c_beg];
	for (int r = r_beg; r < r_end; ++r) {
		for (int c = c_beg; c < c_end; ++c) {
			if (paper[r][c] != cmp)
				return '2';
		}
	}
	return cmp;
}

std::pair<int,int> cut(const std::vector<std::vector<char>>& paper, int r_beg, int c_beg, int r_end, int c_end) {
	std::pair<int, int> num_01{0, 0};
	if (check_full(paper, r_beg, c_beg, r_end, c_end) == '0') 
		++num_01.first;
	else if (check_full(paper, r_beg, c_beg, r_end, c_end) == '1')
		++num_01.second;
	else {
		int r_mid = (r_beg + r_end) / 2;
		int c_mid = (c_beg + c_end) / 2;
		num_01 += cut(paper, r_beg, c_beg, r_mid, c_mid);
		num_01 += cut(paper, r_mid, c_beg, r_end, c_mid);
		num_01 += cut(paper, r_beg, c_mid, r_mid, c_end);
		num_01 += cut(paper, r_mid, c_mid, r_end, c_end);
	}
	return num_01;
}

int main() {
	int N;
	std::vector<std::vector<char>> paper;	// vector<bool> : bitfield
	
	std::cin >> N;
	paper.resize(N);
	for (auto& p : paper) {
		p.resize(N);
		for (char& color : p)
			std::cin >> color;
	}
	
	std::pair<int, int> white_blue =  cut(paper, 0, 0, N, N);
	std::cout << white_blue.first << "\n" << white_blue.second;
	return 0;
}

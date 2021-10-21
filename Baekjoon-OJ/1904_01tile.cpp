#include <iostream>

int tile_num[1000001] = {0, 1, 2}; // not need - just one time

int make_seq(int* tile_num, int N) {
	if (N < 1)
		return 0;
	if (N == 1)
		return 1;
	if (N == 2)
		return 2;
	if (tile_num[N] == 0) {
		tile_num[N] = make_seq(tile_num, N-1) + make_seq(tile_num, N-2);
		tile_num[N] %= 15746;
	}
	return tile_num[N];
}

int main() {
	int N;
	std::cin >> N;
	std::cout << make_seq(tile_num, N);
	return 0;
}

//int main() {
//	int tile_num = 0;
//	int N;
//	std::cin >> N;
//	
//	for (int i = 0; 2 * i <= N; ++i) {
//		int cur_num = 1;
//		int k = 0;		
//		for (int j = i; k < i; ++j, ++k) {
//			cur_num *= N - j;
//		}
//		for (; k > 0; --k) {
//			cur_num /= k;
//		}
//		
//		tile_num += cur_num;
//		if (tile_num > 15746)
//			tile_num %= 15746;
//	}
//	
//	std::cout << tile_num;
//}


// 1
// 00 11
// 100 001 111
// 0000 1100 0011 1001 1111   - 00 2개 00 1개 00 0개  1 + 3 + 1 
// 00001 10000 00100 11100 11001 10011 00111 11111  3 + 4 + 1


// N
// 000 0개 1개 2개 3개 4개 ... 
//           NC0 + (N-1)C1 + (N-2)C2 + (N-3)C3 + ...
// (N+1)C0 + NC1 + (N-1)C2 + (N-2)C3 + ...
// (N+2)C0 + (N+1)C1 + NC2 + (N-1)C3 + ...


// nCr = n-1Cr + n-1Cr-1

// 5 : 1 + 4 + 3 = 8
//         1   3   1
// 6 : 1 + 5 + 6 + 1 = 13
//         1   4   3
// 7 : 1 + 6 + 10 + 4 = 21
//         1    5   6    1
// 8 : 1 + 7 + 15 + 10 + 1 = 34

// 5 + 00 + 6 + 1 = 7
// 6 + 00 + 7 + 1 = 8


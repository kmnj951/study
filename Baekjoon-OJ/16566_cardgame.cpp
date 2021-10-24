#include <iostream>

int cards[4000001];
int vs[10000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M, K;
	std::cin >> N >> M >> K;
	
	//std::vector<int> cards(N + 1); // reszie(>size) == capacity
	//std::vector<int> vs(K);
	
	for (int i = 0; i < M; ++i) {
		int in;
		std::cin >> in;
		cards[in] = -1;	// exist
	}
	
	int greater = 0;
	for (int i = N; i >= 0; --i) {
		if (cards[i] == 0 && greater != 0)
			cards[i] = greater;
		else if (cards[i] < 0)
			greater = i;
	}
	
	for (int i = 0; i < K; ++i) {
		std::cin >> vs[i];
	}
	
	for (int i = 0; i < K; ++i) {
		int find = vs[i] + 1;
		while (cards[find] != -1) {
			find = cards[find];
		}
		std::cout << find << "\n";
		greater = find + 1;
		while (cards[greater] != -1) {
			greater = cards[greater];
		}
		cards[find] = greater;
	}
	
	return 0;
}

// 2 3 4 5 7 8 9

//10 7 5
//2 5 3 7 8 4 9
//4 1 1 3 8
//
//4000000 10 7
//6 4 100 75 23 55 46 11 88 12345
//75 111 7 76 5 11 54

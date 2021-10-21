#include <iostream>
#include <list>
#include <utility>

int N;
int B_line[500001];
int A_preLIS[500001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		std::cin >> a;
		std::cin >> b;
		B_line[b] = a;
	}
	
	std::list<std::pair<int, int> > lis;
	
	int count = N;
	for (int i = 0; i <= 500000 && count > 0; ++i) {
		if (B_line[i] > 0) {
			std::pair<int, int> cur;
			std::list<std::pair<int, int> >::iterator it;
			for (it = lis.begin(); it != lis.end() && !((*it).second < B_line[i]); ++it)
				;
			if (it != lis.end()) {
				cur = std::make_pair((*it).first + 1, B_line[i]);
				A_preLIS[B_line[i]] = (*it).second;
			}				
			else {
				cur = std::make_pair(1, B_line[i]);
				A_preLIS[B_line[i]] = -1;
			}
						
			std::list<std::pair<int, int> >::reverse_iterator rit = make_reverse_iterator(it);
			for (; rit != lis.rend() && !((*rit).first == cur.first); ++rit)
				;
			if (rit == lis.rend())
				lis.insert(rit.base(), cur);
			else if (cur.second < (*rit).second) {
				(*rit).second = cur.second;
			}				
			--count;
		}
	}
	
	int save = lis.front().second;
	while (save != -1) {
		int pre_line = A_preLIS[save];
		A_preLIS[save] = 0;
		save = pre_line;
	}

	count = N - lis.front().first;
	std::cout << count << "\n";
	for (int i = 0; i <= 500000 && count > 0; ++i) {
		if (A_preLIS[i] != 0) {
			std::cout << i << "\n";
			--count;
		}			
	}
	
	return 0;
}

// sort --> first: big, second: small???big???-- smallest!!
// 5 10 -- 9 0
// 4 9 -- 4 0
// 3 4 -- 2 0
// 3 12 -- 5 
// 2 2 -- 1 0
// 2 5 -- 1
// 1 1 -- -1 0
// 1 8 -- -1
// 1 7 -- -1
//   A



//1 8
//2 2
//3 9
//4 1
//5 
//6 4
//7 6
//8 
//9 7
//10 10

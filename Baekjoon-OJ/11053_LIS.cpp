#include <iostream>
#include <utility>
#include <list>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	int A[1000];
	
	std::list<std::pair<int, int> > less_count;
	
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	
	for (int i = 0; i < N; ++i) {
		std::list<std::pair<int, int>>::iterator it;
		std::pair<int, int> cur;
		for (it = less_count.begin(); it != less_count.end() && !(A[i] > (*it).second); ++it)
			;
		if (it != less_count.end())
			cur = std::pair<int, int>((*it).first + 1, A[i]);
		else 
			cur = std::pair<int, int>(1, A[i]);
		
		std::list<std::pair<int, int>>::reverse_iterator rit = make_reverse_iterator(it);	//14
		for (; rit != less_count.rend() && !(cur.first == (*rit).first); ++rit)
			;
		if (cur.second != (*rit).second)
			less_count.insert(rit.base(), cur);
			
//		for (it = less_count.begin(); it != less_count.end(); ++it)
//			std::cout << (*it).first << " " << (*it).second << "\n";
//		std::cout << std::endl;
	}

	std::cout << less_count.front().first;
	return 0;
}


// 8 10 20 10 11 12 13 14 50

// 10 20 10 11 12 13 14 50

// 1,10 
// 2,20 1,10
// 2,20 1,10 1,10
// 2,20 2,11 1,10 1,10
// 3,12 2,20 2,11 1,10

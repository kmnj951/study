#include <iostream>

using namespace std;

class Shom666 {
private:
	int* prefix;
	int prebound[2];
	int* postfix;
	int postdigit;
	static void init(int* num, int size);
	static void next(int* num, int& size);
public:
	Shom666(int size);
	~Shom666();
	void set(int N);
	void print();
};

Shom666::Shom666(int size) 
	: prefix(new int[size]), prebound{0,0}, postfix(new int[size]), postdigit(0) {
	init(prefix,size);
	init(postfix,size);
}

Shom666::~Shom666()  {
	delete prefix;
	delete postfix;
}

void Shom666::init( int* num, int size) {
	for(int i=0; i<size; ++i)
		num[i] = 0;
}

void Shom666::next( int* num, int& size ) {
	int i;
	for(i=0; i<size && num[i]==9; ++i)
		num[i] = 0;
	if(i<size)
		num[i]++;
	else {
		size++;
		num[i] = 1;
	}
}

void Shom666::print() {
	for(int j=prebound[1]-1; j>=prebound[0]; --j)
		printf("%d", prefix[j]);			
	printf("666");
	for(int j=postdigit-1; j>=0; --j)
		printf("%d", postfix[j]);
	printf("\n");
}

void Shom666::set(int N) {
	for(int i=1; i<N; ++i) { 	
		if( postdigit == 0 && prefix[prebound[0]] != 5) { // prefix  
			next(prefix, prebound[1]);
		} 
		else {	// postfix			
			if( postdigit == 0 ) {	// start postfix
				prebound[0]++;
				postdigit++;
				for(int j=prebound[0]; j<prebound[1]; ++j) {
					if( prefix[j] == 6 ) {
						prebound[0]++;
						postdigit++;
					}
					else
						break;
				}		
				init(postfix, postdigit);	
			}
			else {
				int t = postdigit;
				next(postfix, postdigit);
				if( t != postdigit ) { // end postfix
					prebound[0] -= postdigit-1;
					postdigit = 0;
					prefix[prebound[0]] = 7;	
				}
			}
		}
	}
}

int main(void) {
	int N;
	scanf("%d", &N);	
		
	Shom666 s(6);
	s.set(N);
	s.print();
	
	return 0;
}

#include <iostream>
#include <algorithm>

#define abs(a) ((a)>0 ? (a) : -(a))

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	const int goal = N;
	const int b_num = M;
	
	int broken[b_num];
	for(int i=0; i<b_num; ++i) {	
		scanf("%d", &broken[i]);
	}
	if ( b_num == 10 ) {	// all buttons are broken
		printf("%d", abs(goal-100));
		return 0;
	}
	
	sort(broken, broken+b_num);
	
	// int -> array
	int channel[6] = {0};	
	int d;
	if( N == 0 )
		d = 1;
	else
		for(d=0; d<6 && N>0; ++d) {
			channel[d] = N%10;
			N /= 10;
		}
	const int digit = d;

	// find not_broken button (sorted)
	const int nb_num = 10-b_num;
	int not_broken[nb_num];
	int b_index = 0;
	int nb_index = 0;
	for(int i=0; i<10; ++i)
		if( b_index == b_num )
			not_broken[nb_index++] = i;
		else if( i == broken[b_index] ) 
			b_index++;
		else
			not_broken[nb_index++] = i;
			
	// find four candidate ( not over digit )
	int candidate[4][digit];
	int candidate_num = 1;
	for(int i=digit-1; i>=0; --i) {
		int j;
		for(j=0; j<nb_num && channel[i] != not_broken[j]; ++j) 
			;
		if( j<nb_num ) { //channel[i] == not_broken[j]
			// candidate 0
			candidate[0][i] = channel[i];
			candidate[1][i] = channel[i];
			candidate[2][i] = channel[i];
			candidate[3][i] = channel[i];			
		}
		else {	
			candidate_num = 3;
			// candidate 0,1	7[2]7 -> 719, 730
			// 2[5]00 -> 2622, 2388
			for(j=1; j<nb_num && not_broken[j]<channel[i]; ++j) 
				;
			candidate[0][i] = not_broken[j-1];
			if( j<nb_num )
				candidate[1][i] = not_broken[j];
			else	// [9]99
				candidate[1][i] = not_broken[j-1];
			
			for(j=0; j<2; ++j) {
				if( candidate[j][i] < channel[i] )
					for(int k=0; k<i; ++k) 
						candidate[j][k] = not_broken[nb_num-1];
				else
					for(int k=0; k<i; ++k) 
						candidate[j][k] = not_broken[0];
			}
		
			if( i+1<digit ) {
				candidate_num = 4;
				// candidate 2	7[2]7 -> 699, 50[1]1 -> 4999
				for(j=i+1; j<digit && candidate[2][j] == not_broken[0]; ++j) 
					candidate[2][j] = not_broken[nb_num-1];
				if(j<digit) {
					int k;
					for(k=nb_num-2; k>0 && not_broken[k]>=candidate[2][j]; --k) 
						;
					candidate[2][j] = not_broken[k];	
				}	
				else { // 1[0]00 -> 9999 -> 999
					candidate[2][digit-1] = 0;
				}
				for(int k=0; k<=i; ++k) 
						candidate[2][k] = not_broken[nb_num-1];
				
				// candidate 3	5[9]99 -> 6000
				for(j=i+1; j<digit && candidate[3][j] == not_broken[nb_num-1]; ++j) 
					candidate[3][j] = not_broken[0];
				if(j<digit) {
					int k;
					for(k=1; k<nb_num-1 && not_broken[k]<=candidate[3][j]; ++k) 
						;
					candidate[3][j] = not_broken[k];
				}	// 8[9]99 -> 0000 -> over digit
				for(int k=0; k<=i; ++k) 
						candidate[3][k] = not_broken[0];
			}
			else if (digit>1) {
				// candidate 2 [1]000 -> 999
				// 0(...)
				candidate[2][i] = 0;
				for(int k=0; k<i; ++k) 
					candidate[2][k] = not_broken[nb_num-1];
			}
			else // digit==1, only 0
				candidate_num = 2;
						
			break;
		}
	}	
	
	// find minimum in candidate
	int diff_min_zero = 0;
	int diff_min = abs(goal-100) - digit;	// from 100
	for(int i=0; i<candidate_num; ++i) {
		int check = 0;
		int zero_num = 0;
		bool zero = true;
		// array -> int
		for(int j=digit-1; j>=0; --j) {		
			check *= 10;			
			check += candidate[i][j];
			if( zero && j!=0 ) {
				if( candidate[i][j]==0 )
					zero_num++;
				else
					zero = false;
			}		
		}
		int diff = abs(goal-check);	
		if( diff-zero_num < diff_min-diff_min_zero ) {
			diff_min = diff;
			diff_min_zero = zero_num;
		}		
		// cout << check << endl;
	}

	
	int count = digit - diff_min_zero + diff_min;

	//over digit	
	if( digit<6 && digit!=2) {	// 100
		int over = 0;
		if( nb_num>1 && not_broken[1] == 1 ) {
			over = 1;
			for(int i=0; i<digit; ++i)
				over *= 10;
		}
		else if( b_num>0 && not_broken[0] == 1 ) {
			over = 1;
			for(int i=0; i<digit; ++i) {
				over *= 10;
				over += 1;
			}	
		}
		if( over != 0 ) {
			int diff = over-goal;
			if( diff+1 < diff_min-diff_min_zero ) 
				count = digit+1+diff;
		}
	}

	printf("%d", count);
		
	
	return 0;
}

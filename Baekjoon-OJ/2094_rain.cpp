#include <iostream>
#include <map>

using namespace std;

enum { T, F, maybe };

int main(void) {
	//freopen("2094.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	map<int,int> year_index;
	int year[n+1] = {0};
	int rain[n+1] = {0};
	for(int i=1; i<=n; ++i) {
		int y, r;
		scanf("%d%d", &y, &r);
		year_index[y] = i; // >0
		rain[i] = r;
		year[i] = y;
	}

	int m;
	scanf("%d", &m);
	int query[2];
	char answer[3][6] = { "true", "false", "maybe" };
	int ans;
	for(int i=0; i<m; ++i) {
		ans = T;
		scanf("%d%d", &query[0], &query[1]);
		int Y = year_index[query[0]];
		int X = year_index[query[1]];
		if( Y == 0 || X == 0 || X-Y < query[1]-query[0]) 
			ans = maybe;	
		if( Y == 0 && X == 0 )
			ans = maybe;
		else if( Y!=0 && !(rain[Y] >= rain[X]) ) 
			ans = F;	
		else {
			int rain_x = rain[X];			
			int b=0, e=n+1;
			if( Y == 0 ) {
				while(b<e) {
					int t = (b+e+1)/2;		
					if( year[t] <= query[0] )
						b = t;
					else
						e = t-1;
				}
				Y = b;	// equal or less index (but not equal) 
			}
			else if( X == 0 ) {
				while(b<e) {
					int t = (b+e)/2;
					if( year[t] < query[1] )
						b = t+1;
					else
						e = t;
				}
				X = e;	// equal or greater index (but not equal)
				rain_x = rain[Y];
			}
			
			for(int z=Y+1; z<X; ++z) {	// value: exist
				if( !(rain[z] < rain_x) ) {
					ans = F;
					break;
				}			
			}
		}
		//cout << Y << " " << X << endl;
		printf("%s\n", answer[ans]);		
	}
	return 0;
}

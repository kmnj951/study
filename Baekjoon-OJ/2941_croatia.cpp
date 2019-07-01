#include <iostream>

using namespace std;

int main(void) {
	//freopen("input.txt", "r", stdin);
	char ch;
	char pre = 0;
	int count=0;
	while( cin >> ch ) {
		switch( ch ) {
			case '=':
				if( pre == 'c' || pre == 'z' || pre == 's' )
					count--;
				break;
			case 'j':
				if( pre == 'l'|| pre == 'n')
					count--;
				break;
			case '-':
				if( pre == 'c' || pre == 'd')
					count--;
				break;
			case 'z':
				if( pre == 'd')
					if( cin >> ch && ch == '=')
						count--;
					else if ( !cin.fail() )
						count++;			
				break;
			default :
				break;		
		}
		count++;
		pre = ch;
	}
	cout << count;
	return 0;
}


int n ;
cin >> n;
int mask = (1 << 30);
bool first_1_found = false;

while (mask != 0) {
	if ( (( mask & n ) == 0) and  first_1_found == false )  {
		mask = (mask >> 1) ;
		continue;
	}
	else {
		first_1_found = true;
		if (( mask & n) > 0)   { // mistake 1 == improper use of bitwise brakets
			cout << 1 ;
		} // only condition remains is that frist 1 has been found


		else {
			cout << 0 ;
		}
		mask = ( mask >> 1 );		// mistake 2 logical oversight
	}
}



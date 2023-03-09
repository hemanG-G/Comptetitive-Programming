#include <bits/stdc++.h>
using namespace std;
int n ;


// JUST BLACK BOX WTEVER U DONT GET , NO ONE CARES




// black box == it prints THE  length of LIS  from an given array of size n
void lis_length(int n ) {

	// STANDARD METHOD FOR LIS LENGTH REMEMBER ALGO
	// IT JUST WORKS
	int arr[n];
	for ( int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	vector <int> lis; // this is the dynamic lis array that we are operating on
	for (int i = 0 ; i < n ; i ++) {
		// observations
		// 1 ) LIS is always sorted
		// 2 ) minimum last is optimal
		// 3 ) non optimal subsequences are automatically removed
		if (lis.empty() || lis.back() < arr[i]) { // if lis is empty or last element of lis is less then we just add

			lis.push_back(arr[i]);
		}
		else { // we find first elemtn element form right which is less than current element , so that i can add current element just next to it
			// replace the first element greater than arr[i]
			// might be last of LIS or might be before the last of lis
			auto it  = lower_bound(lis.begin(), lis.end(), arr[i]); // found iterator + 1   to first element lesser than y


			*it = arr[i] ; //  added the current number at  next index to element just smaller than current element
		}



		// just to see whats happening
		// basically pinting
		// 1) i (which element we at of array )
		// 2) x ( the lis at every(i) step of iterating the array )
		/*cout << i << " " ;
		for ( auto x : lis) {
			cout << x << ",";
		}
		cout << endl;*/


	}
	cout << lis.size() << endl;
}






// black box == it prints THE LIS is O(nlogn) from an given array of size n
void print_lis(int n) {
	int arr[n];
	int insertedat [n]; // where the element was inserted at
	for ( int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	vector <int> lis;
	for (int i = 0 ; i < n ; i ++) {
		if (lis.empty() || lis.back() < arr[i]) {
			lis.push_back(arr[i]);
			// if it was inserted at end
			insertedat[i] = lis.size()  ; // i th element was inserted at end
		}
		else {
			auto it  = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i] ;
			// if it was inserted at  somewhere int the middle
			insertedat[i] = it - lis.begin() + 1  ; // interator to integer ,hence it - lis.begin ,
		}

		// if u wanna see at what lenght each element was inserted at
		/*for( int i =0 ; i < n ;i++ ){
			cout << insertedat[i] <<  "  " ;
		}
		cout << endl;*/

	}

	vector <int> final_lis;

	int current_length = lis.size();
	for (int i = n - 1 ; i >= 0 ; i--) {
		if ( insertedat[i] == current_length) {
			final_lis.push_back(arr[i]);
			current_length -- ;
		}
	}

	reverse(final_lis.begin(), final_lis.end());

	for ( auto v : final_lis) {
		cout << v << " " ;
	}




}

int main() {

	// PART 1
	// LENGTH OF LIS
	cin >>  n;
	// lis_length(n);



	// PART 2
	// PRINTING  LIS
	print_lis(n);


}


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
	int T;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << convertFive(n) << endl;
	}
}// } Driver Code Ends


/*you are required to complete this method*/
int convert0to5(int n ) {

	if (n == 0 ) return 0 ;

	int rem = n % 10 ;

	if (rem == 0 ) rem = 5 ;

	return rem + convert0to5(n / 10 ) * 10 ;
}



int convertFive(int n) {
	// Your code here
	if (n == 0 ) return 5 ;

	else return convert0to5( n ) ;
}
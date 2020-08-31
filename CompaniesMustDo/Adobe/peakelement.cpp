// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakEle(int *arr , int left,  int right , int n ) {

	int mid = left  + (right - left) / 2 ;

	if ( ( mid == 0 or arr[mid] >= arr[ mid - 1 ] ) and (mid == n - 1 or arr[mid] >=  arr[mid + 1 ])) {
		return mid;
	}
	else if ( mid > 0 and  arr[mid - 1] > arr[mid]) {
		return peakEle(arr , left , mid - 1 , n ) ;
	}
	else {
		return peakEle(arr , mid + 1 , right , n );
	}
}


int peakElement(int arr[], int n)
{
	// Your code here

	return peakEle(arr , 0 , n - 1 , n ) ;


}

// { Driver Code Starts.

int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool f = 0;
		int A = peakElement(a, n);

		if (n == 1)
			f = 1;
		else if (A == 0 and a[0] >= a[1])
			f = 1;
		else if (A == n - 1 and a[n - 1] >= a[n - 2])
			f = 1;
		else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
			f = 1;
		else
			f = 0;

		cout << f << endl;

	}

	return 0;
}  // } Driver Code Ends
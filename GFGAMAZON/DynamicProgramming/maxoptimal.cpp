// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


long long maxProfit(int arr[] , int i , int j , vector<vector<long long >>  &memo ) {

	if ( i == j ) {
		return memo[i][j] =  arr[i];
	}

	if (i > j ) {
		return 0 ;
	}



	if (memo[i][j] != -1 ) return memo[i][j];

	long long  op1 = arr[i] +  min ( maxProfit( arr , i + 1 , j - 1 , memo) , maxProfit( arr , i + 2 , j , memo) ) ;

	long long  op2 = arr[j] + min ( maxProfit( arr , i + 1 , j - 1 , memo ) , maxProfit( arr , i , j - 2  , memo )) ;

	long long  ans = max ( op1 , op2 ) ;

	return memo[i][j] = ans ;
}




long long maximumAmount(int arr[], int n)
{
	// Your code here
	vector<vector<long long >> memo (n + 1 , vector<long long > (n + 1 , -1 )) ;
	long long ans = maxProfit(arr , 0 , n - 1 , memo ) ;

	return ans ;
}

// { Driver Code Starts.

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		int A[N];

		for (int i = 0; i < N; i++)
			cin >> A[i];

		cout << maximumAmount(A, N) << endl;

	}
	return 0;
}  // } Driver Code Ends
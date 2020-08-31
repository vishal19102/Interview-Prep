// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {

    int max_so_far = 0 ;
    int max_curr = 0 ;

    int max_elem = *(max_element(arr , arr + n ));

    if (max_elem < 0 ) return max_elem;

    for (int i = 0 ; i < n ; i++ ) {

        max_curr += arr[i];
        max_so_far = max(max_so_far , max_curr);
        if (max_curr < 0 ) max_curr = 0;
    }
    return max_so_far;
}

// { Driver Code Starts.

int main()
{
    int t, n;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t; //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends
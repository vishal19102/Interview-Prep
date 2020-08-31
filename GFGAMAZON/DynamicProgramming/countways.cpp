// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        cout << countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends


// function to count ways to reach mth stair
long long countWays(int m) {
    // your code here
    long long  a = 1 ;
    long  b = 1 ;

    for (int i = 2 ; i <= m ; i++ ) {
        int temp =  a + b ;
        a = b ;
        b = temp ;
    }
    return b ;
}

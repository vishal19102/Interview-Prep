// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<int , vector<int> , greater<int> > pq ;

    long long  ans = 0 ;
    for (long long  i = 0;  i < n ; i++ ) {
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        int min1 = pq.top();
        pq.pop();
        int min2 = 0 ;
        if (!pq.empty()) {
            min2 = pq.top();
            pq.pop();
            ans += min1 + min2 ;
            pq.push((min1 + min2 ) ) ;
        }

    }
    return ans ;
}
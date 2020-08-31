// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif


int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    // Your code here
    unordered_map<int , int > preIndex ;

    int ans = 0;
    int curSum = 0 ;
    for (int i = 0 ; i < N ; i++ ) {
        int curElem = arr[i];
        if (curElem == 0 ) curSum += -1 ;
        else curSum += arr[i];
        if (curSum == 0 ) {
            ans = max(ans , i + 1 ) ;
        }
        else {
            if (preIndex.find( curSum ) != preIndex.end() ) {
                ans = max(ans , i - preIndex[curSum ]  ) ;
            }
            else
                preIndex[curSum] = i ;
        }
    }
    return ans ;
}

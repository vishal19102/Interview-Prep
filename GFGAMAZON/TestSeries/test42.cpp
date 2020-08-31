// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int ways(int a[], int n);
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
int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n + 5];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << ways(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

int ways(int a[], int n) {

    vector<int> nums ( a , a  + n ) ;
    sort(nums.begin() , nums.end());
    int count = 0 ;
    for (int i = 0 ; i < n ; i++ ) {
        int left = i + 1 ;
        int right = n - 1 ;
        if ( i > 0 and nums[i] == nums[i - 1]) continue;
        int cur_n = nums[i];
        while (left < right ) {
            if (cur_n + nums[left] + nums[right] == 0 ) {
                left++;
                right--;
                count++;
            }
            else if (cur_n + nums[left] + nums[right] < 0 ) {
                left++;
            }
            else
                right--;
        }
    }
    return count ;
}

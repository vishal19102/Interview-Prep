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
int minDist(int arr[], int n, int x, int y);
int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        cout << minDist(a, n, x, y) << endl;
    }
    return 0;
}

int minDist(int a[], int n, int x, int y) {


    int p = -1 ;
    int min_dst = INT_MAX;
    for (int i = 0 ; i < n ; i++ ) {
        if (a[i] == x or a[i] == y ) {

            if (p != -1 and a[p] != a[i] ) {
                min_dst = min (min_dst , i - p ) ;
            }
            p =  i ;

        }
    }
    if (min_dst == INT_MAX)
        return -1;

    return min_dst ;
}
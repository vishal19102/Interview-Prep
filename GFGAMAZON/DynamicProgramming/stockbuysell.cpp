// { Driver Code Starts
// Program to find best buying and selling days

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
// solution structure
struct Interval
{
    int buy;
    int sell;
};



// } Driver Code Ends


// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    if ( n == 0 ) return ;

    int peak = price[0] ;
    int valley = price[0] ;
    int i = 0 ;
    while ( i < n - 1  ) {

        while ( i < n - 1 and price[i] >= price[i + 1] )
            i++;

        valley = i;
        while ( i < n - 1 and price[i] <= price[i + 1 ] )
            i++;

        peak = i ;

        if (valley != peak )
            cout << "(" << valley << " " << peak << ") ";
    }
}
int main()
{

    int price[10000], n, i, T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &price[i]);
        // fucntion call
        stockBuySell(price, n);
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
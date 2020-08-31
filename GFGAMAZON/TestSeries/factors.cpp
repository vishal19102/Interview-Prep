// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll int

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
// } Driver Code Ends


//User function Template for C++
int getCombinations(int cur_divisor , int N) {

    if ( N > 0 and N  % cur_divisor == 0 and N != cur_divisor ) {
        trace(cur_divisor , N , cur_divisor ) ;
        return 1 + getCombinations(cur_divisor , N / cur_divisor );
    }
    else {
        return 0   ;
    }
}


int getFactors(int n) {
    // Code here
    vector<int> divisors ;
    unordered_map<int, bool> notinclude ;
    for (int i = 2 ;  i < n / 2 ; i++) {
        if (n % i == 0 ) {
            divisors.push_back(i);
        }
    }
    //for(auto i : divisors ) cout<<i<<" ";

    int totCombinations = 0 ;
    for (auto i : divisors ) {
        int cur_combinations = getCombinations(i , n ) ;
        //cout<<"cur_comb "<<cur_combinations<< " for i "<<i<<endl;
        totCombinations += cur_combinations ;
    }
    return totCombinations ;
}


// { Driver Code Starts.

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
        int n; cin >> n;
        cout << getFactors(n) << endl;
    }

}
// } Driver Code Ends
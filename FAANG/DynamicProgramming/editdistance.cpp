
// Created By Vishal Srivastava ....
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

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

#define output(x) cout<<x<<"\n";
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;




int editDistance(string str1, string str2, int i , int j , int**  &dp  ) {

    if ( i < 0 ) return j + 1 ;

    if ( j < 0 ) return i + 1 ;

    if (dp[i][j] != -1 ) return dp[i][j];

    int op1 , op2 , op3 , ans = 0;
    if (str1[i] == str2[j] ) ans = editDistance(str1, str2, i - 1, j - 1 , dp);
    else {
        op1 = editDistance(str1, str2, i - 1, j , dp);
        op2 = editDistance(str1, str2, i, j - 1, dp);
        op3 = editDistance(str1, str2, i - 1, j - 1, dp);
        ans = min(op1, min(op2, op3)) + 1 ;
    }

    return dp[i][j] = ans ;
}


int minDistance(string A, string B) {
    int n = A.length();
    int m = B.length();
    int** dp = new int*[n];
    for (int i = 0 ; i < n ; i++ ) {
        dp[i] = new int[m + 1];
        for (int j = 0 ; j <= m ; j++)
            dp[i][j] = -1;
    }
    int ans = editDistance(A, B, n - 1, m - 1 , dp);

    return ans ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int n , m ;
        cin >> n >> m;
        string str1 , str2 ;
        cin >> str1 >> str2;
        cout << minDistance(str1, str2) << endl;
    }
    return 0;
}

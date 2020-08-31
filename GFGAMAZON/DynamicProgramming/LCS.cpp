// { Driver Code Starts
#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;    // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

string str1, str2 ;
int longestSub(int i , int j , vector<vector<int>>  &memo )  {

    if (i < 0 or j  < 0 ) return 0 ;

    if (memo[i][j] != -1 ) return memo[i][j];

    int ans = 0 ;
    if (str1[i] == str2[j]) {
        ans = longestSub(i - 1, j - 1 , memo) + 1 ;
    }
    else {
        ans = max(longestSub(i - 1, j , memo) , longestSub(i , j - 1, memo));
    }

    return memo[i][j] = ans ;
}




int lcs(int x, int y, string s1, string s2) {

    // your code here
    str1 = s1;
    str2 = s2;
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> memo (n + 1 , vector<int> (m + 1, -1 ));
    int ans = longestSub( n - 1  , m - 1, memo );
    return ans ;

}

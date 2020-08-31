
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

int board[10][10] = {0};

bool isPossible(int N , int row , int col ) {

    int i, j;

    /* Check this col on upper side */
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check upper diagonal on right side */
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;

}


void checkQueens(int n , int row ) {

    // solution is found ...
    if ( row == n ) {
        vector<int> res ;
        for (int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < n ; j++ ) {
                if (board[i][j] == 1 ) {
                    res.push_back(j);
                }
            }

        }
        cout << '[';
        for (auto i : res ) cout << i + 1 << " ";
        cout << ']';
        return ;
    }

    //try placing queen at each column position for the row ...
    for (int col = 0 ; col < n ; col++ ) {
        if (isPossible( n , row , col  )) {
            board[row][col] = 1 ;
            checkQueens(n , row + 1 ) ;
            board[row][col] = 0 ;
        }
    }
    // not possible just return ...
    return ;
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
        int n;
        cin >> n;
        checkQueens( n , 0 ) ;
        cout << endl;
    }
    return 0;
}

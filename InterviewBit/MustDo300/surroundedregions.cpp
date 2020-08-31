
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


void floodfill(vector<vector<char> > &board , int x , int y , char prevC , char newC) {

	int n = board.size();
	if ( x < 0 or y < 0 or x >= n or y >= n )
		return ;

	if (board[x][y] != prevC) return ;

	if (board[x][y] == newC ) return ;

	board[x][y] = newC;

	floodfill(board , x + 1 , y , prevC , newC );
	floodfill(board , x - 1  , y , prevC , newC );
	floodfill(board , x  , y + 1 , prevC , newC );
	floodfill(board , x  , y - 1 , prevC , newC );

	return ;
}



void solve(vector<vector<char> > &board) {

	int n = board.size();

	for (int i = 0 ; i < n; i++ ) {
		for (int j = 0 ; j < n ; j++ )
			cout << board[i][j] << " ";
		cout << endl;
	}

	for (int i = 0 ; i < n ; i++  )
		if (board[0][i] == '0' )
			floodfill(board , 0 , i , '0' , 'Y');

	for (int i = 0 ; i < n ; i++ )
		if (board[i][n - 1] == '0')
			floodfill(board , i , n - 1 , '0' , 'Y');

	for (int i = 0 ; i < n ; i++ )
		if (board[n - 1][i] == '0')
			floodfill(board , n - 1 , i , '0' , 'Y');

	for (int i = 0 ; i < n ; i++ )
		if (board[i][0] == '0')
			floodfill(board , i , 0 , '0' , 'Y');

	cout << endl;
	int count =  0 ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0; j < n ; j++ ) {
			if (board[i][j] == 'Y') count++;
		}
	}
	for (int i = 0 ; i < n; i++ ) {
		for (int j = 0 ; j < n ; j++ )
			if (board[i][j] == 'Y' ) board[i][j] = '0';
			else if (board[i][j] == '0') board[i][j]  = 'X';
	}

	for (int i = 0 ; i < n; i++ ) {
		for (int j = 0 ; j < n ; j++ )
			cout << board[i][j] << " ";
		cout << endl;
	}
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
		vector<vector<char> > board ( n );
		for (int i = 0 ; i < n ; i++ ) {
			board[i] = vector<char> ( n );
			for (int j = 0 ; j  < n ; j++ ) {
				cin >> board[i][j];
			}
		}
		solve(board);
	}
	return 0;
}

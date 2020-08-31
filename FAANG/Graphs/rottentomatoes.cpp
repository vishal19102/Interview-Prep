
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


int rotten_oranges(vector<vector<int> > grid , int r , int c  ) {



	queue<pair<pair<int, int>, int> > qu ;

	for (int i = 0 ; i < r ; i++ ) {
		for (int j = 0 ; j < c ; j++ ) {
			if (grid[i][j] == 2 ) {
				pair<pair<int, int> , int >  p = { {i, j} , 0 } ;
				qu.push(p);
			}
		}
	}
	int ans =  0 ;
	int rowvals[] = {  0 , 0 , -1 , 1};
	int colvals[] = {  1 , -1 , 0 , 0};
	while (!qu.empty() ) {
		pair<pair<int, int>, int> fr = qu.front();
		int r = fr.first.first;
		int c = fr.first.second;
		int d = fr.second;
		qu.pop();
		ans = max(ans , d);
		for (int i = 0 ; i < 4 ; i++ ) {
			int newrow = r + rowvals[i];
			int newcol = c + colvals[i];
			if (newrow >= 0 and newrow < grid.size() and newcol  >= 0 and newcol < grid[0].size() and grid[newrow][newcol] == 1) {
				pair<pair<int, int> , int> newp = { {newrow , newcol} , ( d + 1)};
				grid[newrow][newcol] = 2 ;
				qu.push(newp);
			} ;
		}
	}
	for (int i = 0; i < r ; i++ ) {
		for (int j = 0; j < c ; j++ ) {
			if (grid[i][j] == 1 ) return -1;
		}
	}

	return ans;
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
		int r , c;
		cin >> r >> c;
		vector<vector<int> >  grid ;
		for (int i = 0 ; i < r ; i++ ) {
			vector<int> colrow ;
			for (int j = 0 ; j < c ; j++ ) {
				int a ; cin >> a;
				colrow.push_back(a);
			}
			grid.push_back(colrow);
		}

		int ans = rotten_oranges(grid , r , c ) ;
		cout << (ans) << endl;
	}

	return 0;
}

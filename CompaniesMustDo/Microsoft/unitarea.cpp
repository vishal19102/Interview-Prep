
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

#define printBreak() cout << "\n ----------------------" << endl;
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;


bool isValid(int i , int j , vector<vector<int>> &matrix , vector<vector<bool> > &visited ) {

	if ((i >= 0 and i < matrix.size() ) and (j >= 0 and j < matrix[0].size() ) and (matrix[i][j] == 1)  and visited[i][j] == false )
		return true ;

	return false ;
}

int countTot = 0 ;
void dfs(int i , int j , vector<vector<bool>> &visited , vector<vector<int> > &matrix ) {


	visited[i][j] = true;

	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	countTot++;
	for (int steps = 0 ; steps < 8 ; steps++  ) {
		if (isValid(i + dx[steps] , j + dy[steps] , matrix , visited)) {
			dfs(i + dx[steps]  , j + dy[steps] , visited , matrix );
		}
	}
}

int maxArea(vector<vector<int> > &matrix , int n , int m  ) {

	vector<vector<bool> > visited( n , vector<bool> (m , false ));
	int maxCount = 0 ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0 ; j < m ; j++ ) {
			if (isValid( i , j  , matrix , visited) ) {
				dfs(i , j , visited , matrix );
				maxCount = max(maxCount , countTot);
				countTot = 0 ;
			}
		}
	}

	return maxCount ;
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
		int n ;
		cin >> n;
		int m;
		cin >> m;
		vector<vector<int>> matrix ( n , vector<int> ( m , 0));
		for (int i = 0 ; i < n ; i++ )
			for (int j = 0 ; j < m ; j++ )
				cin >> matrix[i][j];

		cout << maxArea(matrix , n , m ) << endl;
	}
	return 0;
}

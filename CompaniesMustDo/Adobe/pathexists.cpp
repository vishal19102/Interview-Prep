
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


int checkPath(vector<vector<int> >  & matrix ) {

	queue<pair<int, int>> qu ;
	int n = matrix.size();
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0 ; j < n ; j++ ) {
			if (matrix[i][j] == 1 ) {
				qu.push({i , j });
				break ;
			}
		}
	}

	int xPos[] = { -1 , 0 , 0 , 1 } ;
	int yPos[] = { 0  , -1 , 1,  0 };
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		if (matrix[fr.first][fr.second] == 2 )
			return 1 ;
		else {
			for (int i = 0 ; i < 4 ; i++ ) {
				int newX = fr.first + xPos[i];
				int newY = fr.second + yPos[i];
				if (newX >= 0 and newX < n and newY >= 0 and newY < n ) {
					if (matrix[newX][newY] == 3 )
						qu.push({newX, newY});
				}

			}
		}
	}

	return 0 ;
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
		cin >> n ;
		vector<vector<int> >  matrix ( n ) ;
		for (int i = 0 ; i < n ; i++ ) {
			matrix[i] = vector<int> ( n , 0 ) ;
			for (int j = 0 ;  j < n; j++ ) {
				cin >> matrix[i][j];
			}
		}
		int ans = checkPath(matrix);
	}
	return 0;
}

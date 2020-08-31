
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

#define printBreak() cout << "----------------------" << endl;
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;


void floodFill(vector<vector<int>> &matrix , int st , int en , int K , int prevC) {

	int n = matrix.size();
	int m = matrix[0].size();

	if (st < 0 or en < 0 or st >=  n or en >= m ) return ;


	if (matrix[st][en] == K)	return ;

	if (matrix[st][en] != prevC ) return ;

	matrix[st][en] = K ;

	floodFill(matrix , st + 1 , en , K , prevC);
	floodFill(matrix , st - 1 , en , K , prevC);
	floodFill(matrix , st  , en + 1, K , prevC);
	floodFill(matrix , st  , en - 1, K , prevC);

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
		int n , m ;
		cin >> n >> m;
		vector<vector<int>> matrix ( n , vector<int> ( m , -1 ));
		for (int i = 0 ; i  < n ; i++ ) {
			for (int j = 0 ; j < m ; j++ )
				cin >> matrix[i][j];
		}
		int st, en, K;
		cin >> st >> en >> K;
		int prevC = matrix[st][en];
		floodFill(matrix , st , en, K , prevC );


		for (int i = 0 ; i  < n ; i++ ) {
			for (int j = 0 ; j < m ; j++ )
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

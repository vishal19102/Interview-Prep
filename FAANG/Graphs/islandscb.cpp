
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


map<int , vector<int> > buildGraph(char** mat , int n , int m) {

	map<int , vector<int> >  adjList ;
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0 ; j < m ; j++ ) {
			if (mat[i][j] == '1') {
				int uniqueidx = i * m + j ;
				if ( (i - 1) >= 0 and  mat[i - 1][j] == '1' ) {
					int temp = (i - 1) * m + j;
					adjList[uniqueidx].push_back(temp);
					adjList[temp].push_back(uniqueidx);
				}
				if ( (j - 1) >= 0 and  mat[i][j - 1] == '1' ) {
					int temp = (i) * m + j - 1 ;
					adjList[uniqueidx].push_back(temp);
					adjList[temp].push_back(uniqueidx);
				}
				adjList[uniqueidx].push_back(uniqueidx);
			}
		}
	}
	return adjList;
}


map<int, bool>   visited ;

void dfs ( int i , map<int , vector<int> >  adjList ) {

	if (visited[i] == true ) return ;

	visited[i] = true;

	for (auto nei : adjList[i]) {
		if (visited[nei] == false and nei != i ) {
			dfs(nei , adjList );
		}
	}

	return ;
}


int noOfIslands(char** mat , int n , int m ) {


	map<int , vector<int> >  adjList = buildGraph ( mat , n , m );

	// for(auto i : adjList ){
	// 	cout<<i.first<<"->";
	// 	for(auto j : i.second) cout<<j<<" ";
	// 	cout<<endl;
	// }

	int count = 0 ;
	int vertices = adjList.size();

	for (auto node : adjList ) visited[node.first] = false;
	for (auto node : adjList ) {
		if (visited[node.first] == false  ) {
			count++ ;
			dfs( node.first , adjList ) ;
		}
	}
	return count ;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n , m ;
	cin >> n >> m;
	char**matrix = new char*[n] ;
	for (int i  = 0 ; i < n ; i++ ) {
		matrix[i] = new char[m];
		for (int j = 0; j < m ; j++ ) {
			char ch ;
			cin >> ch;
			matrix[i][j] = ch ;
		}

	}

	cout << (noOfIslands(matrix, n , m )) << endl;
	return 0;
}


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


vector<bool> visited ;
vector<bool> inStack ;

bool dfs(int i , vector<vector<int>>& adjList ) {

	if (inStack[i] == true ) return true ;

	if (visited[i] == true ) return false ;

	visited[i] = true ;
	inStack[i] = true ;

	for (auto node : adjList[i] ) {
		if (dfs(node , adjList)) return true ;
	}
	inStack[i] = false ;
	return false ;
}

int canFinish(int V, vector<vector<int>>& adjList) {
	// write your awesome code here
	visited = vector<bool> ( V , false );
	inStack = vector<bool> ( V , false );
	for (int i = 0 ; i < V ; i++ )
		if (visited[i] == false ) {
			bool ans = dfs( i , adjList) ;
			if (ans == true ) return 0 ;
		}
	return 1 ;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int V; int E ;
		cin >> V >> E ;
		vector<vector<int> >  adjList( V  );
		for (int i = 0 ; i < E ; i++ ) {
			int u  , v ;
			cin >> u >> v;
			adjList[v].push_back(u);
		}
		trace(canFinish(V , adjList));
	}
	return 0;
}

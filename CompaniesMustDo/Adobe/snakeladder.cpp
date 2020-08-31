
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

int minMoves(unordered_map<int, int> moves ) {

	queue<pair<int, int>> qu ;
	vector<bool> visited (31 , false ) ;
	qu.push({1, 0});
	while ( !qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		int cell = fr.first;
		visited[cell] = true ;
		int dst = fr.second;
		if (cell == 30 ) {
			return dst;
		}

		if (moves.find(cell) != moves.end() and cell > moves[cell]) {
			int newcell = moves[cell];
			pair<int, int> newpair = { newcell , dst + 1 } ;
			if (visited[newcell] != true )
				qu.push(newpair);
		}
		else {
			for (int i = 1 ; i <= 6; i++ ) {
				int newcell = cell + i ;
				if (newcell > 30 ) continue;
				if (moves.find(newcell) != moves.end()) {
					newcell = moves[newcell];
				}
				pair<int, int> newpair = {newcell , dst + 1 } ;
				if (visited[newcell] != true )
					qu.push(newpair);
			}
		}
	}
	return -1;
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
		unordered_map<int, int> moves ;
		for (int i = 0 ; i < n  ; i++ ) {
			int a , b ;
			cin >> a >> b;
			moves[a] = b;
		}
		cout << minMoves(moves) << endl;
	}
	return 0;
}

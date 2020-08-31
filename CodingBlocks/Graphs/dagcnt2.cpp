
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
#include<bitset>
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
#define N 20001


int n , m ;
vector<vector<int>> adjList ( N ) ;
vector<int> topovec ;
vector<int> ind ( N  ) ;
int wt [ N ] ;
void toposort() {

	stack<int> st ;

	for (int i = 1 ; i <= n ; i++ ) {
		if (ind[i] == 0 )
			st.push(i);
	}
	while (!st.empty()) {
		int tp = st.top();
		st.pop();
		topovec.push_back(tp);
		for (auto i : adjList[tp]) {
			ind[i]--;
			if (ind[i] == 0 ) st.push(i);
		}
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
		cin >> n >> m ;
		for (int i = 1 ; i <= n ; i++ ) {
			cin >> wt[i];
		}
		for (int i = 0 ; i < m ; i++ ) {
			int a , b ;
			cin >> a >> b ;
			adjList[a].push_back(b);
			ind[b]++;
		}
		toposort();

		bitset<N> reach [n + 1];
		for (int i = topovec.size() - 1; i >= 0 ; i--) {
			int curN = topovec[i];
			reach[curN].set(curN);
			for (auto it : adjList[curN]) {
				reach[curN] |= reach[it];
			}
		}

		for (int i = 1 ;  i <= n ; i++ ) {
			int val = 0 ;
			for (int j = 1 ; j <= n ; j++ ) {
				if (reach[i][j]) {
					val += wt[j];
				}
			}
			cout << val << " ";
		}
		cout << endl;
		for (int i = 0 ; i <= n ; i++ ) {
			adjList[i].clear(), topovec.clear() , ind.clear();
		}
	}
	return 0;
}

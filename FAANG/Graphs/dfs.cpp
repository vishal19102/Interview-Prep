// { Driver Code Starts
#include<bits/stdc++.h>
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

vector<int> visited ;
vector<int> res ;

void DFS(vector<int>  g[] , int i ) {

	if (visited[i] == true ) return ;

	visited[i] = true ;
	res.push_back(i);
	for (auto neigbour : g[i]) {
		if (visited[neigbour] == false ) {
			DFS(g , neigbour );
		}
	}
}

vector <int> dfs(vector<int> g[], int N)
{
	res.clear();
	visited = vector<int> ( N  , false) ;
	for (int i = 0 ; i < N; i++ ) {
		if (visited[i] == false ) {
			DFS(g, i ) ;
		}
	}
	// for (auto i : res ) cout << i << " ";
	// cout << endl;
	return res ;
}


int main()
{
	int T;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> T;
	while (T--)
	{

		int N, E;
		cin >> N >> E;

		vector<int> g[N];
		bool vis[N];

		memset(vis, false, sizeof(vis));

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector <int> res = dfs(g, N);
		for (int i = 0; i < res.size (); i++)
			cout << res[i] << " ";
		cout << endl;

	}
}
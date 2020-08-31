// { Driver Code Starts
#include <bits/stdc++.h>

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




vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> visited;
vector<int> inStack;
vector<int> res ;


bool dfs(int i , vector<int> adj[] ) {

    if (inStack[i] == true ) return true ;

    if (visited[i] == true ) return false ;

    visited[i] = inStack[i] = true;

    for (auto neig : adj[i]) {
        if (dfs(neig , adj)) {
            return true;
        }
    }

    inStack[i] = false ;
    res.push_back(i);
    return false;
}


vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    visited = vector<int> ( V , false );
    inStack = vector<int> ( V , false );

    for (int i = 0 ; i < V ; i++ ) {
        if (visited[i] == false ) {
            if (dfs(i , adj)) {
                return {};
            }
        }
    }
    reverse(res.begin(), res.end());
    return res ;
}

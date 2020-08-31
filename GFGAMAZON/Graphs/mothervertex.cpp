// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


void dfs(int v , vector<int>  &visited , vector<int>  adjList[] ) {

    if (visited[v] == true ) return ;


    visited[v] = true ;

    for (auto i : adjList[v]) {
        if (visited[i] == false )
            dfs(i , visited , adjList );
    }
    return ;
}


int findMother(int V, vector<int> g[])
{
    // Your code here
    vector<int> visited (V , false ) ;
    int  v = 0 ;
    for (int i = 0 ; i < V ; i++ ) {
        if (visited[i] == false ) {
            dfs(i , visited , g);
            v = i ;
        }
    }
    fill(visited.begin(), visited.end()  , false );

    dfs( v , visited , g ) ;

    for (int i = 0; i < V ; i++ )
        if (visited[i] == false )
            return -1 ;

    return v ;
}

int main()
{
    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--) {
        int num, edges;
        cin >> num >> edges;

        vector<int> adj[num];

        int u, v;
        while (edges--) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << findMother(num, adj) << endl;
    }

    return 0;
}   // } Driver Code Ends
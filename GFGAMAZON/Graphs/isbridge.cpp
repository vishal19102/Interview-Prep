// { Driver Code Starts
// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main() {

    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

void dfs(int i , list<int> adj[] , vector<bool> &visited) {

    if (visited[i] == true ) return ;

    visited[i] = true ;

    cout << i << " ";
    for (auto node : adj[i]) {
        if (visited[node] == false ) {
            dfs( node , adj , visited);
        }
    }
    return ;
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    // Code here
    int oldComps = 0 ;
    vector<bool> visited (V , false );
    for (int i = 0 ; i < V ; i++ ) {
        if (visited[i] == false ) {
            dfs(i , adj , visited);
            cout << endl;
            oldComps++;
        }
    }
    adj[s].remove(e);
    adj[e].remove(s);
    int newComps = 0;
    cout << "--------------------" << endl;
    fill(visited.begin(), visited.end() , false );
    for (int i = 0 ; i < V ; i++ ) {
        if (visited[i] == false ) {
            dfs(i , adj , visited);
            cout << endl;
            newComps++;
        }
    }
    cout << "-----------------------" << endl;
    return newComps != oldComps;
}
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


int scc = 0 ;
void sccUtil( int i , vector<int> &disc , vector<int> &low , vector<bool> &visited ,  stack<int> &st , vector<int> adj[]) {

    static int time = 0 ;

    disc[i] = low[i] = ++time ;
    st.push(i);
    visited[i] = true;

    for (auto node : adj[i]) {
        if (disc[node] == -1 ) {
            sccUtil(node, disc, low, visited, st, adj);
            low[i]  = min(low[i], low[node]);
        }
        else if (visited[node] == true ) {
            low[i] = min(low[i] , disc[node]);
        }
    }
    int cur_node = 0;
    if (disc[i] == low[i]) {
        while ( st.top() != i ) {
            cur_node = st.top();
            st.pop();
            visited[cur_node] = false ;
            //cout << cur_node << " ";
        }
        cur_node = st.top();
        st.pop();
        visited[cur_node] = false;
        // cout << cur_node << ",";
        // cout << endl;
        scc++;
    }
}


int kosaraju(int V, vector<int> adj[])
{
    vector<int> disc(V, -1 );
    vector<int> low(V , -1);
    vector<bool> visited(V , false );
    stack<int> st;

    for (int i = 0 ; i < V ; i++ ) {
        if (disc[i] == -1 ) {
            sccUtil( i , disc , low , visited , st , adj) ;
        }
    }
    int ans = scc;
    scc = 0 ;
    return (ans);
}

// { Driver Code Starts.

int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
// } Driver Code Ends
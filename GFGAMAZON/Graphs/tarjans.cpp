// { Driver Code Starts
#include <bits/stdc++.h>
#define NIL -1
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
void find(vector<int> adj[], int N);

int main() {

    int t; // number of test cases
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m; // n- number of nodes and m- number of edges

        vector<int> adj[n + 1]; // adjacency list

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        find (adj, n);
        cout << "\n";
    }
}// } Driver Code Ends

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
            cout << cur_node << " ";
        }
        cur_node = st.top();
        st.pop();
        visited[cur_node] = false;
        cout << cur_node << ",";
        cout << endl;
        scc++;
    }
}


void find(vector<int> adj[], int V) {

    vector<int> disc(V, -1 );
    vector<int> low(V , -1);
    vector<bool> visited(V , false );
    stack<int> st;

    for (int i = 0 ; i < V ; i++ ) {
        if (disc[i] == -1 ) {
            sccUtil( i , disc , low , visited , st , adj) ;
        }
    }
    trace(scc);
    scc = 0 ;
}

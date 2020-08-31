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

void sccutil(int u , vector<int>  &disc , vector<int> &low , stack<int> st ,  vector<bool> inStack , vector<int>  adj[]) {

    static int time = 0 ;

    disc[u] = low[u] = ++time ;
    st.push(u);
    inStack[u] = true ;

    // adjacent ....
    for (auto v : adj[u]) {
        if (disc[v] == -1 ) {
            sccutil(v , disc, low, st , inStack , adj) ;
            low[u] = min(low[u] , low[v]);
        }
        else if ( inStack[v] == true ) {
            low[u] = min(low[u] , disc[v]);
        }
    }

    // if true ....
    int cur_node = 0 ;

    if (disc[u] == low[u]) {
        while (st.top() != u ) {
            cur_node = st.top();
            st.pop();
            cout << cur_node << " ";
            inStack[cur_node] = false ;
        }
        cur_node = st.top();
        st.pop();
        cout << cur_node << ",";
        inStack[cur_node] = false ;
    }
}


void find(vector<int> adj[], int V) {

    vector<int> disc(V , -1 );
    vector<int> low(V , -1 ) ;
    stack<int> st;
    vector<bool> inStack(V , false ) ;


    for (int i = 0 ; i < V ; i++ ) {
        if (disc[i] == - 1) {
            sccutil(i , disc, low , st , inStack , adj );
        }
    }
}

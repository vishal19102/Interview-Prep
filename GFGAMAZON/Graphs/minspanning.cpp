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
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

struct Edge
{
    int src;
    int desc;
    int weight;

};

bool cmp(Edge &a , Edge &b) {

    return a.weight < b.weight;
}



vector<int> parent;
vector<int> rankN;

int find(int a ) {

    if (parent[a] == a ) return a;
    int rep = find(parent[a]);
    parent[a] = rep ;
    return rep ;
}

void unionbyrankN(int a , int b ) {

    int repa = find(a);
    int repb = find(b);

    if (repa == repb ) return ;

    if (rankN[repa] > rankN[repb]) {
        parent[repb] = repa;
    }
    else if (rankN[repa] < rankN[repb]) {
        parent[repa] = repb;
    }
    else {
        parent[repa] = repb;
        rankN[repb]++;
    }
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here

    // for (int i = 0 ; i < V ; i++ ) {
    //     for (int j = 0 ; j < V ; j++ ) {
    //         trace(graph[i][j]);
    //     }
    // }

    vector<Edge> edgeList ;
    for (int i = 0 ; i < V ; i++ ) {
        for (int j = 0 ; j < V ; j++ ) {
            if (graph[i][j] != 0 and graph[i][j] != INT_MAX ) {
                Edge e = { i , j , graph[i][j]};
                edgeList.push_back(e);
            }
        }
    }
    int cur_edges = 0;
    int curWeight = 0 ;

    sort(edgeList.begin(), edgeList.end() , cmp);

    for (auto [sr, de, we ] : edgeList ) {
        trace(sr, de, we);
    }

    for (int i = 0 ; i < V ; i++) {
        parent.push_back(i) ;
        rankN.push_back(0) ;
    }

    for (int i = 0 ; i < edgeList.size() ; i++ ) {

        if (cur_edges == V - 1 ) {
            break ;
        }
        int sr = edgeList[i].src;
        int desc = edgeList[i].desc;
        if (find(sr) != find(desc)) {
            curWeight += edgeList[i].weight;
            cur_edges++;
            unionbyrankN(sr, desc);
        }
    }
    rankN.clear() , parent.clear();
    return curWeight ;
}
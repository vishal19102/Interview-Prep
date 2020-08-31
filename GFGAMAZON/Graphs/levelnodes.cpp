// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*  Function to find level of node X

g[] : adjacency list of the given graph
N : number of vertices
X : The destination node
*/
int levels(vector<int> g[], int N, int X)
{

    queue<pair<int, int>> qu ;
    qu.push({0 , 0 });
    vector<bool>  visited(N , false );
    int ans = 0 ;
    while (!qu.empty()) {
        pair<int, int> fr = qu.front();
        qu.pop();
        visited[fr.first] = true;
        if (fr.first == X ) {
            ans =  fr.second ;
            break;
        }
        for (auto i : g[fr.first ]) {
            if (visited[i] == false ) {
                qu.push({i , fr.second + 1});
            }
        }
    }
    return ans ;
}


int main() {

    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;

    while (t--) {

        int n, e;
        cin >> n >> e;
        vector<int> g[n];
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int x;
        cin >> x;

        cout << levels(g, n, x) << endl;
    }

    return 0;
}  // } Driver Code Ends
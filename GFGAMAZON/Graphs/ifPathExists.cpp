// { Driver Code Starts
#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}

void buildGraph(vector<vector<int> >  &matrix , int  N , uordered_map<int , vector<int> > adjList ) {

    for (int i = 0; i < N ; i++ ) {
        for (int j = 0 ; j < N ; j++ ) {
            int unique_val = i * N + j ;
            if ( i + 1 < N  and matrix[i + 1 ][j] != 0) {
                int temp_val = (i + 1) * N + j ;
                adjList[unique_val].push_back(temp_val);
            }
        }
    }
}

bool is_possible(vector <vector <int>> &M, int N) {

    uordered_map<int , vector<int> > adjList ;

    buildGraph(M , N , adjList);

    dfs(src , adjList ) ;
}

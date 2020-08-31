// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int , int );

int printSolution(vector <int> dist, int n)
{

  for (int i = 0; i < n; i++)
    printf("%d ", dist[i]);

  return 0 ;
}
int main()
{
  int t;
  int V;
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> V;

    vector<vector<int>> g(V);

    for (int i = 0; i < V; i++) {
      vector<int> temp(V);
      g[i] = temp;
    }

    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        cin >> g[i][j];
      }
    }

    int s;
    cin >> s;

    vector <int> res = dijkstra(g, s, V);
    printSolution (res, V);
    cout << endl;
  }
  return 0;
}

int findMinVertex(vector<int>  distances  , vector<bool> visited , int V) {

  int minVertex = -1 ;
  for (int i = 0;  i < V; i++ ) {
    if (!visited[i] and (minVertex == -1 or distances[minVertex] > distances[i]))
      minVertex = i ;
  }
  return minVertex;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
  vector<int>  distances(V  , INT_MAX) ;
  vector<bool> visited (V , false ) ;


  distances[src] = 0 ;

  for (int i = 0 ; i < V - 1 ; i++ ) {

    int minVertex = findMinVertex (distances , visited , V ) ;
    visited[minVertex] = true;
    for (int j = 0 ; j < V ; j++ ) {
      if (!visited[j] and g[minVertex][j] != 0 and distances[j] > distances[minVertex] + g[minVertex][j] )
        distances[j] = distances[minVertex] + g[minVertex][j];
    }
  }

  return distances ;
}
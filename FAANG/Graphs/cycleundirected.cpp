
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


vector<int> visited ; 
bool dfs(int i , int parent  , vector<int> adjList[]){

	if(visited[i] == true and i != parent )
		 return true ;

	if(visited[i] == true ) return false;

	visited[i] = true ; 

	for(auto j : adjList[i] ){
		if( j != parent ){
			if(dfs(j , i , adjList)) {
				return true; 
			}
		}
		
	}

	return false ; 
}


bool isCyclic(vector<int> g[], int V)
{
   // Your code here
	visited = vector<int> (V ,false);
   
   	for(int i = 0 ; i < V ; i++ ) {
   		if(visited[i]!= true ){
   			if(dfs(i , -1 , g)) {
   			return true ; 
   			}
   		}
   		
   	}

   	return false;
}

// { Driver Code Starts.


int main()
{
	
	#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int T;

    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
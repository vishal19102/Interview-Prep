
// Created By Vishal Srivastava .... 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

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

#define output(x) cout<<x<<"\n";
#define long long int int 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string,int> pp;


// vector<bool>  visited;
// vector<bool> inStack ; 

// void dfs(int x, int parent) {
//     vis[x] = true;
//     inStack[x] = true;
//     for(int u = 0; u < n; u++) {
//         if (graph[x][u] == 1 && u != parent && vis[u] && inStack[u]) {
//             // there is a cycle: u -> ... -> parent -> x
//         }
//         if(!vis[u] && graph[x][u] == 1) {
//             dfs(u, x);
//         }
//     }
//     inStack[x] = false;
//     order.push_back(x);
// }

vector<int> res ; 
bool dfs ( int i , vector<vector<int> > &adjList ,  vector<bool> &visited , vector<bool> &inStack ){


	if(inStack[i] == true ) return true;

	if(visited[i] == true ) return false ; 

	visited[i] = true;
	inStack[i] = true;

	for(auto neigbour : adjList[i]){
		if(dfs(neigbour,adjList , visited , inStack ))
				return true; 
	}
	inStack[i] = false;
	res.push_back(i);
	return false; 
}
 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
	vector<bool> visited( n , false);
	vector<bool> inStack( n , false);

	for(int i = 0; i < n ; i++ ) {
		if(visited[i] != true ) {
			bool ans = dfs(i , prerequisites , visited , inStack );
			if(ans == true ) return ans;
		}
	}
	return false ;
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int> > adjList ( nodes ) ;

    for(int i = 0 ; i < edges ; i ++ ){
    	int u , v;
    	cin>>u>>v;
    	adjList[v].push_back(u);
    } 

    if(canFinish(nodes , adjList)){
    	cout<<"No"<<endl;
    }
    else{
    	cout<<"Yes"<<endl;
    }
    return 0;
}



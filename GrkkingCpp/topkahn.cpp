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


void kahntopo(int n , vector<vector<int>> adjList , std::vector<int> indegre) {

	queue<int > que ; 

	vector<int> results;
	for(int i = 1 ;  i <=n ; i++)
			if(indegre[i]==0)
				que.push(i);


	while(!que.empty()){
		int a = que.front();
		que.pop();
		results.push_back(a);
		for(auto node : adjList[a]){
			indegre[node]--;
			if(indegre[node]==0)
					que.push(node);
		}
	}

	for(auto node : results)
		trace(node);

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
   	int n , m ;
   	cin>> n >> m;

   	vector<vector<int>> adjList( n+1 ) ;
   	vector<int> indegree ( n+1 ) ;


   	for(int i = 1 ; i <=m ;i ++ ){
   		int a, b ;
   		cin>>a >>b;
   		adjList[a].push_back(b);
   		indegree[b] += 1 ;

   	}

   	// for(int i= 1 ; i <=n;i++){
   	// 	cout<<i<<" -> ";

   	// 	for(auto k : adjList[i]){
   	// 		cout<< k <<" ";
   	// 	}
   	// 	cout<<endl;
   	// 	cout<<indegree[i]<<endl;

   	// }
   	kahntopo( n , adjList ,indegree) ;

   	
    return 0;
}

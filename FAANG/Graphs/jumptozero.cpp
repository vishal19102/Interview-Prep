
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

bool jumpzero(vector<int>  arr ,int start) {

	bool ans = false;

	map<int , vector<int> > adjList;

	int n = arr.size();

	for(int i = 1 ; i <=n ;i++ ){
		int a = i + arr[i];
		int b = i - arr[i]; 
		if(a < n )
			adjList[i].push_back(a);
		if(b > 0 )
			adjList[i].push_back(b);
	}


	queue<int> qu ; 

	qu.push(start);


	map<int , bool > visited ;


	visited[start] = true ;


	while(!qu.empty()){
		int f = qu.front();
		qu.pop();
		if(arr[f] == 0 )
			return true;

		for(auto i : adjList[f]){
			if(visited[i]==false){
				qu.push(i);
				visited[i] = true;
			}
		}
	}


	return ans ;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n , start;
    cin>>n>>start;
    vector<int> arr ( n+1 ) ;

    for(int i = 1 ; i <= n ; i++ )
    	cin>>arr[i];	



    bool ans = jumpzero(arr,start);
    if(ans)
    	cout<<"YES"<<endl;
    else
    	cout<<"NO"<<endl;
    return 0;
}

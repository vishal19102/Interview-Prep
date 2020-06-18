
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

bool isBipartite(map<int,set<int>> adjList ) {

    bool ans = true ; 

    int n = adjList.size();

    vector<string> colors ( n+1  , "white" ) ;

    for(int i = 1; i <=n ; i++ ) {
        if(colors[i]=="white"){
            queue<int> qu ; 
            qu.push(i);
            colors[i] = "blue";

            while(!qu.empty()){
                int f = qu.front();
                qu.pop();

                for(auto node : adjList[f]){
                    if(colors[node]=="white"){
                        if(colors[f]=="blue")
                            colors[node]="red";
                        else
                            colors[node]="blue";
                        qu.push(node);
                    }
                    else
                        if(colors[f]==colors[node])                            return false;
                    
                }

            }
        }


    }

    trace("came out " ) ;



    return ans;
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
       #endif
    int  n;
    cin>> n ;
    map<int,set<int> > adjList;

    for(int i = 0 ; i< n ; i++ ){
        int a,b;
        cin>>a>>b;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }
    
   
    cout<<isBipartite(adjList)<<endl;

    return 0;
}

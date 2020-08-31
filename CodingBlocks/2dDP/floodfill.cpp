
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


int minColors(vector<int> &colors , int st , int en , int** dp ){

	if(st >= en ) return 0 ;

	if(dp[st][en]!=-1) return dp[st][en];

	int ans = 0 ; 
	if(colors[st] == colors[en]){
		ans = minColors(colors , st+1 , en-1 ,dp);
		return dp[st][en] = ans + 1;
	}
	else{
		int op1 = minColors(colors,st+1,en ,dp);
		int op2 = minColors(colors,st,en-1 ,dp);
		ans = min(op1,op2) + 1 ;
		return dp[st][en] = ans ;
	}
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ;
    cin>>n;
    vector<int> colors ( n ) ;
    for(int i = 0 ; i < n ; i++ ) cin>>colors[i];
    int** dp = new int*[n];
	for(int i = 0 ; i < n ; i++ ) {
		dp[i]= new int[n];
		for(int j = 0 ; j < n ; j++ ) 
			dp[i][j] = -1;
	}

    cout<<minColors(colors , 0 , n-1 ,dp)<<endl;
    return 0;
}

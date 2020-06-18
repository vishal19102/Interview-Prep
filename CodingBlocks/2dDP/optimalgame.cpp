
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


int dp[10001][10001];

int maxPossible(vector<int>  &arr ,int st ,int en ) { 

	if(st==en)
		return arr[st];

	if(st > en )
		return  0 ;

	if(dp[st][en]!=-1)
		return dp[st][en];

	int op1 = maxPossible(arr ,st , en-2);
	int op2 = maxPossible(arr ,st+1 , en-1);
	int op3 = maxPossible(arr ,st+2 , en);

	op1 = min(op1 , op2 ) + arr[en];
	op2 = min(op2 , op3 ) + arr[st];

	int ans = max(op1,op2);

	trace(st,en,op1,op2,op3);
	return dp[st][en] = ans;
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
    vector<int> arr ( n );

    for(int i = 0 ; i < n ; i++ ) 
    	cin>>arr[i];

    memset(dp,-1,sizeof dp);
    trace(maxPossible(arr ,0 , n-1));
    return 0;
}

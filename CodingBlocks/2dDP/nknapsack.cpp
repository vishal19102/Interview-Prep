
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

int dp[1001][1001];

int maxPossible(vector<int> wt, vector<int> val ,int pos , int cap ) {


	if( pos < 0 || cap < 0 ) 
		return 0 ;

	if(dp[pos][cap]!=-1)
		return dp[pos][cap];

	int op1 = maxPossible(wt,val,pos-1,cap);
	int op2 = 0 ,op3 = 0 ;

	if(wt[pos] <= cap ){
 		op2 = maxPossible(wt,val,pos-1,cap - wt[pos]) + val[pos];
		op3 = maxPossible(wt,val,pos,cap - wt[pos]) + val[pos];
	}
	int ans = max(op1,max(op2,op3));

	return dp[pos][cap] = ans ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ,s;
    cin>>n>>s;

    vector<int> wt ( n ) , val ( n ) ;

    for(int i = 0 ; i < n ; i++ )
    	cin>>wt[i];

    for(int i = 0 ; i < n ; i++ )
    	cin>>val[i];

    memset(dp , -1, sizeof dp );

    cout<<maxPossible(wt,val,n-1,s)<<endl;
    return 0;
}

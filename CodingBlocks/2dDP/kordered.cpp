
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

int dp[2005][2005][5];

int klcs(vector<int> arr1, vector<int>  arr2 , int i , int j , int k ) { 

	if( i < 0 || j < 0 )
		return 0 ;

	int ans = 0 ;

	if(dp[i][j][k]!=-1)
		return dp[i][j][k];

	if(arr1[i]==arr2[j])
		ans = klcs(arr1,arr2,i-1,j-1,k  ) + 1 ;

	else{
		int op1 = INT_MIN;
		if(k > 0 )
			 op1 = klcs(arr1,arr2,i-1,j-1,k-1 ) + 1 ;

		int op2 = klcs(arr1,arr2,i-1,j,k );
		int op3 = klcs(arr1,arr2,i,j-1,k);
		ans = max(op1,max(op2,op3));

	}
	return dp[i][j][k] = ans ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ,m,k;
    cin>>n>>m>>k;

    vector<int> arr1(n),arr2(m);

    for(int i = 0 ; i < n ; i++ )
    	cin>>arr1[i];

    for(int i = 0 ; i < m ; i++ )
    	cin>>arr2[i];

    memset(dp,-1,sizeof dp);
    

    cout<<klcs(arr1,arr2,n-1 ,m-1 , k  )<<endl;

    return 0;
}

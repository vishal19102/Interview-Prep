
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


int minPathSum(int st , int en ,vector<vector<int> > mat  ,int n , int m , vector<vector<int> > dp){

    if (st == n-1 and en == m-1 ) return mat[st][en] ;

    if( st >= n or en >= m ) return INT_MAX ;

    if(dp[st][en] != -1 ) return dp[st][en];

    int op1 = minPathSum(st+1 , en ,mat , n , m ,dp) ;
    int op2 = minPathSum(st , en + 1  ,mat , n , m ,dp) ;

    //trace(op1 ,op2 ,st ,en );

    int ans = min(op1 ,op2 ) + mat[st][en];

    return dp[st][en] =  ans ;
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n , m ;
    cin>>n>>m;
    vector<vector<int> > matrix ( n );
    for(int i = 0 ; i < n ; i++ ){
    	matrix[i] = vector<int> ( m );
    	for(int j = 0 ; j < m ; j++ ) 
    		cin>>matrix[i][j];
   	}
    vector<vector<int> >   dp ( n ) ;
        for(int i  = 0 ; i < n ; i++ ){
            dp[i] = vector<int> ( m );
            fill(dp[i].begin(), dp[i].end() , -1 );
    }
   	cout<<(minPathSum( 0 , 0  , matrix , n , m , dp))<<endl;
    return 0;
}
 
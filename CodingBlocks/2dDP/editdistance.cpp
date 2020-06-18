
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


int dp[2001][2001];

int mindistance(string str1,string str2,int i , int j ) {

	int ans = 0 ;
	
	if( i==0)
		return j;
	if(j==0)
		return i;

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(str1[i-1]==str2[j-1])
		ans = mindistance(str1,str2,i-1,j-1);
	else{
		int op1 = mindistance(str1,str2,i-1,j-1);
		int op2 = mindistance(str1,str2,i-1,j);
		int op3 = mindistance(str1,str2,i,j-1);
		ans = min(op1,min(op2,op3)) + 1;
	}


	dp[i][j] = ans;


	return dp[i][j] ;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str1,str2;

    cin>>str1>>str2;

    int n = str1.length();
    int m = str2.length();

    memset(dp,-1,sizeof dp);

    cout<<mindistance(str1,str2,n,m)<<endl;
    return 0;
}

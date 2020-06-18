
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

int dp[11][11][11][11];

int countbits(string a) {
	int ans = 0;
	for(auto i: a )
		if(i=='1')
			ans++;
	return ans;
}

int maxpossible(int pos , int ca, int cb,int cc){

	if( pos  < 0 ){
		trace(ca,cb,cc);
		return 0 ; 
	} 

	if(ca==0 && cb==0 && cc==0 )
		return 0 ;


	if(dp[pos][ca][cb][cc]!=-1)
		return dp[pos][ca][cb][cc];

	int ans = 0;

	int op1 = 0 ,op2 =  0 , op3 = 0  , op4  = 0; 

	if(ca > 0 )
		 op1 = maxpossible(pos-1 , ca-1,cb,cc);
	if(cb > 0 )
		 op2 = maxpossible(pos-1 , ca,cb-1,cc);
	if(cc > 0 )
		 op3 = maxpossible(pos-1 , ca,cb,cc-1);
	if(ca > 0 && cb > 0 && cc > 0 )
		op4 = maxpossible(pos-1 , ca-1,cb-1,cc-1);

	ans =  max ( max(op1,max(op2,op3)) , op4 )  ;

	ans = ans  + pow(2 , (pos));
	return dp[pos][ca][cb][cc] = ans ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    cin>>t;
    while(t--){
      string a, b, c;
      cin>>a>>b>>c;
      int ca = countbits(a);
      int cb = countbits(b);
      int cc = countbits(c);

      memset(dp , -1 ,sizeof(dp));

      int n =  maxpossible(9 , ca,cb,cc ) ;

    int binaryNum[10];

    int i = 0; 
	    while (n > 0) { 
	  
	        binaryNum[i] = n % 2; 
	        n = n / 2; 
	        i++; 
	    }
	       for (int j = i - 1; j >= 0; j--) 
        		cout << binaryNum[j]; 

	    cout<<endl;

    }

    return 0;
}

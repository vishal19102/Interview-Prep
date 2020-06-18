
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

int collectballs(vector<int> a , vector<int> b )  { 

	int ans = 0 ;

	vector<int>  prefixa ( a.size() ) , prefixb ( b.size() ) ;

	prefixa[0] = a[0];
	prefixb[0] = b[0];
	
	for(int i =1 ;i < a.size();i++){
		prefixa[i] = prefixa[i-1] + a[i] ; 
	}


	for(int i =1 ;i < b.size();i++)
		prefixb[i] = prefixb[i-1] + b[i] ; 

	vector<pair<int,int>> intersect ( min(a.size(),b.size()));


	int i = 0 , j = 0 ,k = 0;

	while((i < a.size()) && (j < b.size()) ) { 
		if(a[i]==b[j]){
			intersect[k++] = {i , j } ;
			i++;
			j++;

		}
		else if ( a[i] < b[j] )
			i++;
		else{
			j++; 	
		}

	}
	int op1 =  0; 
	int op2 = 0 ;
	int idx1 = intersect[0].first;
	int idx2 = intersect[0].second;

	op1 = prefixa[idx1] - prefixa[0] + a[0];
	op2 = prefixb[idx2] - prefixb[0] + b[0];

	trace(idx1,idx2,op1,op2);

	ans = max( op1 ,op2 ) ;

	trace(ans) ;

	for(int i = 1 ; i < k ; i++ ) { 

		int idx1n = intersect[i].first;
		int idx2n= intersect[i].second;

		op1 = prefixa[idx1n] - prefixa[idx1];
		op2 = prefixa[idx2n] - prefixb[idx2];
		ans += max ( op1 ,op2 ) ;
		idx2 = idx2n;
		idx1 = idx1n;
		trace(idx1,idx2,op1,op2);

	}


	return ans ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>t;
    while(t--){
      int n , m ;
      cin>>n>>m;
      //trace(n,m);
      std::vector<int> v1 ( n ) ,v2 ( m ) ;

      for(int i = 0 ; i < n ; i++ )
      	cin>>v1[i];

      for(int j = 0 ; j < m ;j++ )
      	cin>>v2[j];


      trace(collectballs(v1,v2));

    }	
    return 0;
}

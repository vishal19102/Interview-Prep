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


vector<int> sieve ( ) { 

	vector<bool> isprimes ( 100001 ) ; 

	for(int i = 0; i<=100001;i++ ){
		isprimes[i] = true; 
	}
	isprimes[0] = false ; 
	isprimes[1] = false ;
	for(int i = 2 ; i*i<= 100001 ; i++)  {

		if(isprimes[i]) { 
			for(int j = i*i ; j <=100001 ; j+= i ) { 
				isprimes[j] = false ; 
			}
		}
	}

	vector<int> primes ; 

	for(int i = 0 ; i <= 100001 ; i++)
			if(isprimes[i])
				primes.push_back(i);

	return primes ; 
}

void segsieve ( int l ,int r , vector<int> primes  ) { 

	bool segprimes[r-l+1 ] ;

	for(int i = 0 ; i < (r-l+1) ; i++ ) 
		segprimes[i] = true;

	for(int i =0 ; primes[i] *primes[i] <= r ; i++) { 

		int curPrime = primes[i] ; 

		int base = (l /curPrime) * curPrime ;

		if(base < l )
			base = base + curPrime ;

		for(int j = base ; j <=r ; j += curPrime)
			segprimes[j-l] = false;

		if(base==curPrime)
			segprimes[base-l] = true;

	}

	for(int i = 0 ; i < (r-l) ; i++)
		if(segprimes[i])
			cout<<i+l<<" ";


	return ; 
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<int> primes = sieve ( ) ;

    cin>>t;
    while(t--){
      int l ,  r ;
      cin>>l>>r;
      segsieve ( l ,r  , primes );
    }
    return 0;
}

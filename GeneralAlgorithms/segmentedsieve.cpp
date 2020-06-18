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

std::vector<int> sieve( ) {

	std::vector<bool> primes  ( 1000001 ) ;

	for(int i = 0 ; i <= 1000001 ; i++ ) 
		primes[i]  = true ; 

	primes[0] = false ;

	for(int i = 2 ; i*i <= 1000001; i++ ) { 
		if(primes[i]){
			for(int j = i *i ; j <=1000001;j += i )  
				primes[j] = false; 
		}
	}

	std::vector<int> isprimes;

	for(int i =2 ; i < 1000001 ; i++ ) { 
		if(primes[i]) 
			isprimes.push_back ( i ) ;

	}
	return isprimes ; 
}

void segsieve ( int l , int r , std::vector<int> primes ) { 

	bool sieveprimes [ r-l+1 ] ; 
	
	for(int i = 0 ; i < (r-l+1 ) ; i++)
		sieveprimes[i] = true ;

	for(int i = 0 ; primes[i]*primes[i]<= r ; i++)  {

		int curPrime = primes[i] ; 

		int base = (l / curPrime) * curPrime ;

		if(base < l )
			base = base + curPrime ;

		for(int j = base; j <= r ; j += curPrime)  { 
			sieveprimes[j-l] = false ;
		}

		if(base==curPrime) { 
			sieveprimes[base-l] = true ; 
		}
	}
	for(int i = 0 ; i <= (r-l) ; i++ ) { 
		if(sieveprimes[i]) { 
			cout<<i+l<<" " ; 
		}
	}
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
    cin>>t;
    vector<int> primes ( 1000001 );

    primes = sieve ( ) ;

    while(t--){
      int l , r ; 
      cin>>l>>r ;
      segsieve(l , r , primes ) ;
    }
    return 0;
}

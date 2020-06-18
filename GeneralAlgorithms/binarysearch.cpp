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

void binary_search(int* arr, int n , int key ) { 

	int start = 0 ;
	int end = n ;

	while( start <= end )  { 

		int mid = start + (end - start) / 2;
		if(arr[mid]==key){
			cout<<" Key found at : "<<mid ;
			return ; 
		}
		else if ( arr[mid] < key )
			start =  mid-1;
		else
			end = mid + 1 ; 
	}
	cout<<"Key not present  .........."<< endl;



	return  ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n ,key;
    cin>>n>>key;

    int* arr = new int[ n ] ;

    for(int i = 0 ; i < n;i++) 
    	cin>>arr[i];


    binary_search(arr, n , key) ;
    return 0;
}

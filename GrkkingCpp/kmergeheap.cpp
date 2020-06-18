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

struct MinHeapNode 
{ 
    int element; 
    int i; 
    int j; 
}; 

int comparefun(MinHeapNode* a, MinHeapNode* b ){

	if(a->element < b->element )
		return true;
	
}

vector<int> mergelists(vector<vector<int>> lists){


	std::vector<int> res;

	int minheap = lists.size();

	priority_queue<MinHeapNode , std::vector<MinHeapNode> v;  , comparefun<MinHeapNode> > kheap ; 


	int minlength = minheap; 

	while(minlength>=0){

		kheap.push(lists[minlength][0]);
	}

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n , k ; 
    cin>> n >> k;
    vector<vector<int>> lists ( n )  ;

    for(int i = 0 ; i < n ; i++){
    	int m ;
    	cin>> m ;
    	for(int j = 0 ; j < m;j++){
    		int a ;
    		cin>> a;
    		lists[i].push_back(a);
    	}
    }

    for(auto list : lists){

    	for(auto i : list){
    		cout<<i<<" ";
    	}
    	cout<<endl;
    }

    mergelists(lists);

    return 0;
}

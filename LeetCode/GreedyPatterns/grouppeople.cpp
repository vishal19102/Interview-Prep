
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

 vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,pair<int,vector<int> >>counts ; 
        
        for(int i = 0 ; i < groupSizes.size() ; i++ ){
            counts[groupSizes[i]].first += 1 ;
            counts[groupSizes[i]].second.push_back( i );
        }
       
        vector<vector<int>> res ;
        
        for(auto i : counts ){
                if(i.first == (i.second).first){
                    res.push_back((i.second).second);
                }
                else{
                    vector<int> temp ; 
                    int times = i.first; 
                    int k = 0 ,curtime = 1 ;
                    int nn = ((i.second).second).size();
                    for(int j = 0 ; j < nn ; j++ ) {
                    	temp.push_back((i.second).second[k++]) ;
                    	if(curtime == times ){
                    		res.push_back(temp);
                    		temp.clear();
                    		curtime = 1 ;
                    	}
                    	else{
                    		curtime++;  
                    	}
                      
                    }                   
                }    
        }
     
    for(auto i : res ) {
    	for(auto j : i ) 
    		cout<<j<<" ";
    	cout<<endl;
    }
    return res ;
    }

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
   	int n;
   	cin>>n;
   	vector<int>  groupSizes ( n );
   	for(int i = 0 ; i < n ; i++ )
   		cin>>groupSizes[i];
   	groupThePeople(groupSizes);

    return 0;
}

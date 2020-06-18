
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

struct  Pair
{
	string s;
	int depth;

	Pair(string st ,int dp ){
		s = st;
		depth = dp;
	}
};

vector<string>  neigbours(set<string> words ,string start) {

	vector<string>  res ;

	for(int i = 0 ; i < start.length() ; i++ ) {
		string temp = start;
		for(char j = 'A' ; j <= 'Z' ; j++ )  { 
			temp[i] = j ;
			if(words.count(temp) != 0 ){
				// /trace(temp);
				res.push_back(temp);
				words.erase(temp);

			}

		}


	}
	return res;

}
int mintransform(vector<string>  w , string start , string end  )  {


	queue<Pair> qu ; 

	set<string> words (w.begin(),w.end());


	qu.push({start,1});

	while(!qu.empty()){

		Pair cur = qu.front();
		qu.pop();

		vector<string> adjList = neigbours(words , cur.s ) ;

		for(auto st : adjList ){

			if(end==st)
				return cur.depth+ 1 ;

			qu.push({st,cur.depth+1});
		}


	}
	return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string start;
    string end ;
    cin>>start>>end;
    int n ;
    cin>>n;
    vector<string> words( n ) ;
    for(int i = 0 ; i < n ; i++ ) { 
    	cin>>words[i];
    }
    cout<<mintransform(words , start  ,end )  ; 
    return 0;
}

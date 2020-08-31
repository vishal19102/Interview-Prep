
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

string table[10] 
        = { "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz" };

void allCombinations(string str , int pos ,vector<string>  &res , string curr ){

	if(pos == str.length()){
		res.push_back(curr );
		return ; 
	}
	string ch = table[str[pos] - '0'];
	for(int i = 0 ; i < ch.length(); i++ ){
		string s(1, ch[i]); 
		curr += s;
		allCombinations(str,pos+1,res,curr);
		curr.pop_back();
	}

}

vector<string> letterCombinations(string A) {
    
    vector<string> res ; 
    string cur = "";
    allCombinations(A , 0 , res ,cur );
    for(auto i : res ) trace(i);
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
    string str;
    cin>>str;
    letterCombinations(str);
    return 0;
}

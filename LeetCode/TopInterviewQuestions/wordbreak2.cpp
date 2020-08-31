
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


void StringToInt(vector<string> &nums , string str1 ){

	str1 = str1.substr(1,str1.size()-2);
	char* str = new char(str1.length() + 1 );
	strcpy(str ,str1.c_str() ); 
	char* token = strtok(str , ",");
	while(token != NULL ) {
		nums.push_back(token);
		token = strtok(NULL , ",");
	}
}

void breakWords(unordered_map<string,bool> words , string text , string &cur , vector<string> &resultants) {
	
	if(text.length() <= 0 ){
		resultants.push_back(cur.substr(0 , cur.length()-2));
		cur = "";
		return ;
	} 
	for(int i = 0 ;  i <text.length();i++){
		string temp = text.substr(0 , i+1);
		if(words.count(temp) != 0 ){
			temp += " ";
			cur += temp;
			breakWords(words , text.substr(i+1 ) , cur , resultants);
			
		}
		
	}
	return  ; 
}

vector<string>  wordBreak(string s, vector<string>& wordDict) {
     
    int n = s.length();
    unordered_map<string, bool > dict; 
    for(auto i : wordDict) dict[i] = true ;
    string res =  "";
	vector<string> results ;
	breakWords(dict , s , res  ,results);
	return results;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string text ;
    cin>>text;
    string str ;
    cin>>str;
    vector<string> words ;
    StringToInt(words , str );
    wordBreak(text , words);
    return 0;
}

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


int* findLPS( string pat) { 

	int* lps = new int[ pat.length()]();
	lps[0] = 0;
	int i = 0 ;
	int j =  1;

	while(j < pat.length()){

		if(pat[i]==pat[j]){
			lps[j] = i+ 1;
			i++;
			j++;
		}
		else if ( i!=0)
				i = lps[i-1];
		else {
			lps[j] = 0 ;
			j++ ;
		}

	}

return lps;

}


void kmp(string text, string pat, int* lps ) {

	int tl = text.length();
	int pl = pat.length();

	int i = 0;
	int j = 0 ;

	while( i <tl && j < pl ) {

		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else {
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}

	}
	if(j==pl)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

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
   	string text, patt;
   	cin>>text>>patt;

   	int* lps = findLPS(patt);

   	kmp(text,patt,lps);
    return 0;
}

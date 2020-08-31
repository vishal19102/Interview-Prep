// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
int isValid(char *);
int main() {
    // your code goes here
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
}// } Driver Code Ends

int checkValidity(string str , int pos , int n ) {


    string res = "";

    int i = 0 ;
    while ( i < n ) {
        while (str[i] != '.') {
            res += str[i];
            i++;
        }
        trace(res);
        res = "";
        if (str[i + 1] == '.') return 0 ;
    }

    return 1 ;
}



int isValid(char *ip) {
    // your code here
    string str (ip);
    int n = str.length();
    int ans = checkValidity(str , 0 , n);

    return 0 ;
}
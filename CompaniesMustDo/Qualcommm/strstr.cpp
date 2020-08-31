#include<bits/stdc++.h>
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

int strstr(string , string);

int main()
{
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << strstr(a, b) << endl;
    }
}

int* getLPS ( string patt ) {

    int* lps = new int[patt.length()];
    lps[0] = 0 ;

    int i = 0 ;
    int j = 1 ;

    while ( j < patt.length()) {

        if (patt[i] == patt[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else {
            if ( i != 0 )
                i = lps[i - 1];
            else {
                lps[j] = 0 ;
                j++;
            }
        }

    }


    return lps;
}
int strstr(string s, string x)
{
    //Your code here
    int* lps = getLPS(x);

    int i = 0;
    int j = 0;

    while ( i < s.length() and j < x.length() ) {
        if (s[i] == x[j]) {
            i++;
            j++;
        }
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if ( j == x.length() ) return (i - x.length());

    return -1 ;
}
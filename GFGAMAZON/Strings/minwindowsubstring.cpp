// { Driver Code Starts
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

string smallestWindow (string S, string P) {
    // Your code here
    unordered_map<char , pair<int, int> > mp ;

    for (auto i : P )  {
        pair<int, int> p = { mp[i].first + 1 , 0 };
        mp[i] = p ;
    }

    for (auto i : mp ) {
        trace(i.first , i.second.first , i.second.second );
    }

    int st = 0 ;
    int en = 0 ;
    int min_window = INT_MAX;
    int start_m = 0;
    int matches = 0 ;
    while ( en < S.length() ) {
        char ch = S[en++];
        if (mp.find(ch) != mp.end()) {
            (mp[ch].first)--;
            if (mp[ch].first <= 0 ) {
                if (mp[ch].second == 0 ) {
                    trace(ch , mp[ch].first , mp[ch].second );
                    matches++;
                    mp[ch].second = 1 ;
                }
            }
        }
        while (matches == P.length()) {
            //trace(min_window);
            if (min_window  > ( en - st + 1 )) {
                min_window = en - st + 1 ;
                start_m = st ;
            }
            char ch_st = S[st++];
            if (mp.find(ch_st) != mp.end() ) {
                (mp[ch_st].first)++;
                if ((mp[ch_st].first ) > 0 ) {
                    //trace("in restrict");
                    matches--;
                    mp[ch_st].second = 0;
                }
            }
        }
    }

    if ( min_window > S.length() ) return "-1";

    else return S.substr(start_m , min_window  ) ;
}

// { Driver Code Starts.
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
        string s;
        cin >> s;
        string pat;
        cin >> pat;

        cout << smallestWindow(s, pat) << endl;

    }
    return 0;
}

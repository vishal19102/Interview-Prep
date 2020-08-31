// { Driver Code Starts
//Initial function template for C++

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
vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> , int );

// User code will be pasted here

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
        vector<pair<int, int> > arr, res;
        int n, x, y;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }

        res = overlappedInterval(arr, n);


        for (int i = 0; i < res.size(); i++)
            cout << res[i].first << " " << res[i].second << " " ;

        cout << endl;
    }
}
// } Driver Code Ends


//User function template for C++

bool cmp(pair<int, int> &a , pair<int, int> &b) {

    return a.first < b.first;
}


vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> vec, int n) {
    //code here

    if (vec.size() <= 1 ) return vec ;

    sort(vec.begin(), vec.end() , cmp);

    for (auto [st , en] : vec ) trace(st , en );

    vector<pair<int, int>>  res ;
    res.push_back(vec[0]);

    int resIndex = 0 ;
    for (auto [st , en ]  : vec ) {
        trace(res[resIndex].first , res[resIndex].second );
        pair<int, int> fback = res[resIndex];
        res.pop_back();
        int cur_eb = fback.second;
        if (cur_eb >= st ) {
            cur_eb = max(cur_eb , en );
            res.push_back({fback.first , cur_eb});
        }
        else {
            res.push_back(fback);
            res.push_back({st , en });
            resIndex++;
        }

    }
    return res ;
}


3 ......................................................88
5 ................ 28
16............................61
19.
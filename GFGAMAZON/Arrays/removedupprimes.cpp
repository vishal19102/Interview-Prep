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
vector<int> removeDuplicate(vector<int>& arr, int n);

int main()
{
    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        vector<int>result = removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;

    }
}
// } Driver Code Ends

#define MAX 101

vector<int> primes ;

void sieve() {
    vector<int> isPrimes (MAX , true ) ;

    isPrimes[1] = false;
    isPrimes[0] = false;

    for (int i = 2 ; i * i < MAX; i++ ) {
        if (isPrimes[i] == true  ) {
            for (int j = i * i ; j < MAX ; j += i ) {
                isPrimes[j] = false ;
            }
        }
    }

    for (int i = 2 ; i < MAX ; i++ ) {
        if (isPrimes[i]) primes.push_back(i);
    }
    return ;
}

vector<int> removeDuplicate(vector<int>& arr, int n)
{
    // code here
    sieve();
    unordered_map<int , bool > isPresent ;
    vector<int> res ;
    for (auto i : arr ) {
        if (isPresent.find(i)  == isPresent.end()) {
            res.push_back(i);
        }
        isPresent[i] = true ;
    }
    return res;
}



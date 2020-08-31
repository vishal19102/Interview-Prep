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
int bin_search(int A[], int left, int right, int k);

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
        int N;

        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        int key;
        cin >> key;
        int found = bin_search(a, 0, N - 1, key);
        cout << found << endl;
    }
}

int bin_search(int A[], int left, int right, int k)
{
    if ( left > right ) return -1 ;

    int mid = left + (right - left ) / 2 ;

    if (A[mid] == k ) return mid ;

    if (A[mid] > k )
        return bin_search(A , left , mid - 1, k);
    else
        return  bin_search(A , mid + 1, right, k);

}
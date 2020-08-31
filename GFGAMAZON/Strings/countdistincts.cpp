// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector <int> result = countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends




vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    unordered_map<int, int > freq_k ;

    vector<int>  res ;
    for (int i = 0 ; i < n - k + 1 ; i++) {

        if (freq_k.size() != k ) {
            freq_k[A[i]]++;

        }
        else {
            res.push_back(freq_k.size());
            freq_k[]
        }
    }
}
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
string MostFrequent(string paragraph, vector<string> taboo) ;


// } Driver Code Ends


//User function Template for C++

string MostFrequent(string paragraph, vector<string> taboo)
{
    // Your Code
    unordered_map<string , bool > badWords ;

    for (auto su : taboo ) {
        transform(su.begin(), su.end(), su.begin(), ::tolower);
        badWords[su] = true;
    }


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
        cin.ignore();
        string paragraph;
        getline(cin, paragraph);
        int n;
        cin >> n;
        vector<string> taboo(n);
        for (int i = 0; i < n; ++i)
            cin >> taboo[i];
        cout << MostFrequent(paragraph, taboo) << endl;
    }

    return 0;
}   // } Driver Code Ends
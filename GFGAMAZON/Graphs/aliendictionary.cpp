// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}


class Graph
{
public:
    unordered_map<char , vector<char> > adjList;
    set<char> characters ;
    void buildGraph( string dict[] , int N ) {

        for (int i = 0 ; i < N - 1 ; i++ ) {
            string str1 = dict[i];
            string str2 = dict[i + 1 ];
            for (int j = 0 ; j < min(str1.length(), str2.length() ) ; j++ ) {
                if (str1[j] != str2[j]) {
                    adjList[str1[j]].push_back(str2[j]);
                    characters.insert(str1[j]);
                    characters.insert(str2[j]);
                    break;
                }
            }
        }
        // for (auto [ch , lst ] : adjList ) {
        //     cout << ch << "---->";
        //     for (auto adj : lst )
        //         cout << adj << " ";
        //     cout << endl;
        // }
    }


    void dfs (string &str , unordered_map<char, bool>  &visited , char ch ) {

        if (visited[ch] == true ) return  ;

        visited[ch] = true;

        for (auto neighs : adjList[ch]) {
            if (visited[neighs] == false )
                dfs(str , visited , neighs ) ;
        }

        str.push_back(ch);

        return ;
    }
};




string findOrder(string dict[], int N, int K) {
    // Your code here

    Graph g = Graph();
    g.buildGraph(dict, N);
    string str = "";
    unordered_map<char,  bool > visited ;
    set<char > chs = g.characters;
    for (auto i : chs) visited[i] = false ;

    for (auto j : chs ) {
        if (visited[j] == false ) {
            g.dfs(str , visited , j );
        }
    }

    reverse(str.begin(), str.end()) ;
    return str;
}
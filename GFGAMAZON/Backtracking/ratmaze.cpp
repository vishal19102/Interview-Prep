// { Driver Code Starts
// Initial template for C++

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
#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

int dx[] = { -1 , 1 , 0 , 0 } ;
int dy[] = { 0 , 0 , -1 , 1 } ;
char dir[] = {'U' , 'D' , 'L' , 'R'};


bool isSafe(int i , int j , int m[MAX][MAX] , int n ) {

    if (i >= n or j >= n or i < 0 or j < 0 ) return false;

    if (m[i][j] == 2 or m[i][j] == 0 ) return false;

    return true;

}

void ratMaze(int m[MAX][MAX] , int n , vector<string>  &path , int st , int en , string cur_path) {

    if (st == n - 1 and en == n - 1 ) {
        path.push_back(cur_path);
        return ;
    }
    for (int i = 0 ; i < 4  ; i++ ) {
        int newst = st + dx[i];
        int newen = en + dy[i];
        if (isSafe(newst, newen , m , n )) {
            m[newst][newen] = 2;
            cur_path.push_back(dir[i]);
            ratMaze(m , n , path , newst , newen , cur_path );
            cur_path.pop_back();
            m[newst][newen] = 1;
        }
    }


}


vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here

    vector<string>  ans;
    string path = "";
    m[0][0] = 2 ;
    ratMaze( m , n , ans, 0 , 0, path );

    return ans;
}

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
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
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
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
string path;
vector<string> paths;
int Path[MAX][MAX];

void tryPath(int m[MAX][MAX] , int n , int x , int y ) {


    if( x == (n-1 ) and y == (n-1 )) {
        Path[x][y] = 1;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ) 
                cout<<Path[i][j]<<" ";  
            cout<<endl;
        }
        return ; 
    }

    if( x < 0 || x >=  n || y < 0 || y >= n ) {
        return ; 
    }

    if( m[x][y] == 0 or Path[x][y] == 1 ){
        return ; 
    }

    Path[x][y] = 1 ; 
    //right ...
    tryPath( m , n , x , y+1 );

    //left ...
    tryPath( m , n , x , y-1);

    //top ..
    tryPath( m , n , x-1 , y );

    //bottom..
    tryPath( m , n , x+1 , y );

    Path[x][y] = 0 ;
    return ; 
}




vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here

    tryPath ( m , n , 0 , 0 ) ;


    return paths ;
}

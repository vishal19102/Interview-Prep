
// Created By Vishal Srivastava .... 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

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

#define output(x) cout<<x<<"\n";
#define long long int int 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string,int> pp;


bool isPossible(int board[9][9] , int row ,int col ,int val ) {

// is row safe...
for(int i = 0 ; i <= col ; i++ ){
  if(board[row][i] == val ) false ;
}
// is column safe...
for(int i = 0 ; i <= row ; i++ ){
  if(board[i][col] == val ) false ;
}

// is box safe...
  for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i+row][j+col] == val)
                return false;

  return true;

}


void solveSudoku(int board[9][9]){

	int row , col ;
  bool isEmpty = false ; 

  // search for empty position ... 
  for(int i = 0 ; i < 9 ; i++ ) {
    for(int j = 0; j < 9 ; j++ ){
      if(board[i][j] == 0 ) {
        row = i ; col = j ; 
        isEmpty = true;
        break;
      }
    }  
    if( isEmpty ) break;
  }

  if( !isEmpty ) {

    // print solution...
    for(int i = 0 ; i < 9 ; i++ ){
      for(int j = 0 ; j < 0 ; j++ ){
        cout<<board[i][j]<<" ";
      }
      cout<<endl;
    }
    return ; 
  }

  //try combinations....
  for(int i = 0 ; i < 9 ; i++ ) {
      if(isPossible(board , row, col , i ) ) {
        board[row][col] = i ; 
        solveSudoku(board);
        board[row][col] = 0 ;
      }
  } 
	return  ;
  
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    cin>>t;
    while(t--){
   		int board[9][9] ;
   		for(int i = 0 ; i < 9 ; i++ ){
   			for(int j = 0 ; j < 9 ; j++ ){
   				cin>>board[i][j];
   			}
   		}
   		solveSudoku(board);
    }
    return 0;
}

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
int wildCard(string pattern, string str);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string pat, text;
		cin >> pat;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> text;
		cout << wildCard(pat, text) << endl;
	}
}

string str1 ;
string str2 ;

int solve(int i , int j , vector<vector<int> >  &memo ) {

	if ( i < 0  and j < 0  ) return 1 ;

	if ( j < 0 ) return 0 ;

	if (i < 0 ) {
		while ( j >= 0 ) {
			if (str2[j] == '*')
				j--;
			else
				return 0 ;
		}
		return 1 ;
	}

	if (memo[i][j] != -1 ) return memo[i][j];

	int ans = 0 ;
	if (str1[i] == str2[j] or str2[j] == '?' ) {
		ans = solve(i - 1 , j - 1 , memo );
	}
	else if ( str2[j] == '*' ) {
		int op1 = solve(i - 1, j, memo);
		int op2 = solve(i , j - 1, memo);
		ans = op1 | op2  ;
	}
	else return memo[i][j] = 0 ;

	return memo[i][j] = ans ;
}

int wildCard(string pattern, string str)
{

	int m = str.size();
	int n = pattern.size();
	str1 = str;
	str2 = pattern;
	vector<vector<int>> memo ( m , vector<int> (n , -1 ));

	int ans = solve(m - 1 , n - 1 , memo);

	return ans ;
}
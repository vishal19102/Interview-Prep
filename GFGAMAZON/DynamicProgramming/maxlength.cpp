// { Driver Code Starts
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
struct val {
	int first;
	int second;
};



int maxChainLen(struct val p[], int n);
int main() {
	// your code goes here
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		val p[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].first >> p[i].second;
		}

		cout << maxChainLen(p, n) << endl;
	}
	return 0;
}
bool cmp(val &a , val &b ) {

	return a.first < b.first;
}

int maxChainLen(struct val p[], int n)
{
//Your code here
	sort( p , p + n , cmp );

	vector<int> memo ( n , 1 );

	int maxans = 0 ;
	for (int i = 1 ; i < n ; i++ ) {
		int st = p[i].first;
		for (int j = i - 1 ; j >= 0 ; j-- ) {
			int preven = p[j].second;
			if (preven < st ) {
				memo[i] = max(memo[j] + 1 , memo[i]);
			}
		}
		maxans = max(maxans , memo[i]);
	}
	return maxans;
}
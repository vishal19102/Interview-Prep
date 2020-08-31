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
// } Driver Code Ends




vector <int> nearlySorted(int arr[], int num, int K) {
	// Your code here
	priority_queue<int , vector<int>  , greater<int> >  qu;

	vector<int>  res ;

	for (int i = 0 ; i < K + 1 and i < num ; i++ ) {
		qu.push(arr[i]);
	}

	int i = K + 1;
	while (!qu.empty()) {
		int min_e = qu.top();
		qu.pop();
		res.push_back(min_e);
		if (i < num ) {
			qu.push(arr[i++]);
		}
	}
	return res ;
}

// { Driver Code Starts.

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
		int num, K;
		cin >> num >> K;

		int arr[num];
		for (int i = 0; i < num; ++i) {
			cin >> arr[i];
		}

		vector <int> res = nearlySorted(arr, num, K);
		for (int i = 0; i < res.size (); i++)
			cout << res[i] << " ";

		cout << endl;
	}

	return 0;
}
// } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


// } Driver Code Ends


string rearrangeString(string str) {
	// Your code here
	int freq[26] = {0};
	for (int i = 0 ; i < str.length(); i++ ) {
		freq[(int) str[i] - 'a']++;
	}
	priority_queue<pair<int, char>> pq ;

	for (int i = 0 ; i < 26 ; i++ ) {
		if (freq[i] > 0 ) {
			pq.push(make_pair(freq[i] , (char) ('a' + i)));
		}
	}

	string res = "";
	while (!pq.empty()) {

		if (pq.size() >= 2) {
			pair<int, char> p1 = pq.top();
			pq.pop();
			pair<int, char> p2 = pq.top();
			pq.pop();
			res.push_back(p1.second);
			res.push_back(p2.second);
			p1.first--;
			p2.first--;
			if (p1.first)
				pq.push(p1);
			if (p2.first)
				pq.push(p2);
		}
		else if ( pq.size() == 1) {
			if (pq.top().first > 1 ) return "-1";
			else {
				res.push_back(pq.top().second);
				pq.pop();
			}
		}
	}
	return res ;
}

int main()
{
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	cin.ignore(INT_MAX, '\n');
	while (t--)
	{
		string str;
		cin >> str;
		str = rearrangeString(str);
		int flag = 1;
		if (str != "-1") {
			for (int i = 1; i < str.length(); i++) {
				if (str[i - 1] == str[i])
					flag = 0;
			}
			if (flag == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else
			cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
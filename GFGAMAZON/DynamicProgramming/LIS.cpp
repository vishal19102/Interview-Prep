

// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[])
{
	// your code here
	vector<int> memo ( n , 1 ) ;
	int maxAns = 1 ;

	for (int i = 1 ;  i < n ; i++ ) {

		for (int j = i - 1 ; j >= 0 ; j-- ) {
			if (a[i] > a[j]) {
				memo[i] = max(a[j] + 1 , a[i]);
			}
		}
		maxAns = max(maxAns , memo[i]);
	}

	return maxAns;
}

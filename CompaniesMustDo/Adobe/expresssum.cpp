#include<bits/stdc++.h>
using namespace std;

int uniqueNum(int x, int n, int start)
{
	if (x == 0)
		return 1;

	if (x < 0)
		return 0;

	if (start == 0)
		return 0;

	int value = pow(start, n);
	return uniqueNum(x - value, n, start - 1) + uniqueNum(x, n, start - 1);

}

int main()
{
	int test_case;
	cin >> test_case;

	double x, n;

	while (test_case--)
	{
		int start;
		cin >> x >> n;

		start = pow(x, (1 / n));

		cout << uniqueNum(x, n, start) << "\n";

	}
	return 0;
}
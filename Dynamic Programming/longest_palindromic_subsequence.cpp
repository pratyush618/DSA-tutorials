// Source has been copied from longest common subsequence problem.

#include <bits/stdc++.h>
using namespace std;

// Tabulation
/*int lcs(string &s, string &t) {
	int m = s.length();
	int n = t.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}*/

// Space Optimized
int lcs(string &s, string &t) {
	int m = s.length();
	int n = t.length();
	vector<int>previous (n + 1, 0), current (n + 1, 0);

	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0) current[j] = 0;
			else if (s[i - 1] == t[j - 1]) current[j] = 1 + previous[j - 1];
			else current[j] = max(previous[j], current[j - 1]);
		}
		previous = current;
	}

	return previous[n];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x;

	// cout << "Enter string 1 : ";
	cin >> x;
	string y = string(x.rbegin(), x.rend());

	cout << lcs(x, y);

	return 0;
}
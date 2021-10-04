#include<bits/stdc++.h>
using namespace std;
static int t[100][100];

//top down
int LCS(string x, string y, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	if (t[n][m] != -1)
		return t[n][m];
	if (x[n - 1] != y[m - 1])
		return t[n][m] = max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
	return t[n][m] = 1 + LCS(x, y, n - 1, m - 1);
}
int main()
{
	// string x = "abedfghr", y = "abcdgh";
	string x, y;
	cin >> x;
	cin >> y;
// 	memset(t, -1, sizeof(t));
// 	cout << LCS(x, y, x.length(), y.length()) << endl;

  	
	int n = x.length();
	int m = y.length();
  //bottom up
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				t[i][j] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (x[i - 1] == y[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	cout << t[n][m] << endl;
}

// BOJ 3085 :: ªÁ≈¡ ∞‘¿”
#include <bits/stdc++.h>
using namespace std;
char c[50][50];
int ans = 0;
int cntr = 0;
int cnth = 0;
void func(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j > 0 && c[i][j] != c[i][j - 1] )
			{
				swap(c[i][j], c[i][j-1]);
				char cc = c[0][0];
				char ccc = c[0][0];
				cntr = 0;
				cnth = 0;
				for (int k = 0; k < n; ++k)
				{
					for (int l = 0; l < n; ++l)
					{
						if (cc != c[k][l])
						{
							cc = c[k][l];
							ans = max(ans, cntr);
							cntr = 1;
						}
						else
							cntr++;
						if (ccc != c[l][k])
						{
							ccc = c[l][k];
							ans = max(ans, cnth);
							cnth = 1;
						}
						else
							cnth++;
					}
					ans = max({ ans,cntr,cnth });
					char cc = c[0][0];
					char ccc = c[0][0];
					cntr = 0;
					cnth = 0;
				}
				swap(c[i][j], c[i][j - 1]);
			}
			if (i > 0 && c[i][j] != c[i-1][j])
			{
				swap(c[i][j], c[i - 1][j]);
				char cc = c[0][0];
				char ccc = c[0][0];
				cntr = 0;
				cnth = 0;
				for (int k = 0; k < n; ++k)
				{
					for (int l = 0; l < n; ++l)
					{
						if (cc != c[k][l])
						{
							cc = c[k][l];
							ans = max(ans, cntr);
							cntr = 1;
						}
						else
							cntr++;
						if (ccc != c[l][k])
						{
							ccc = c[l][k];
							ans = max(ans, cnth);
							cnth = 1;
						}
						else
							cnth++;
					}
					ans = max({ ans,cntr,cnth });
					char cc = c[0][0];
					char ccc = c[0][0];
					cntr = 0;
					cnth = 0;
				}
				swap(c[i][j], c[i - 1][j]);
			}
				
		}
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}
	func(n);
	cout << ans;
	return 0;
}
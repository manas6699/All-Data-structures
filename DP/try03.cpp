#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k , n , W;
	k = n = W = 2;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> K[i][j];
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << K[i][j] << " - ";
		}
		
	}
	

	return 0;
}
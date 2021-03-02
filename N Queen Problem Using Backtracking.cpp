#include <bits/stdc++.h>
using namespace std;
int n, i, j; bool board[11][11];
bool is_safe(int x, int y)
{
	for(int i = 1; i < y; i++) if(board[x][i]) return false;
	for(int i = x, j = y; i and j; i--, j--) if(board[i][j]) return false;
	for(int i = x, j = y; i <= n and j; i++, j--) if(board[i][j]) return false;
	return true;
}

bool f(int x)
{
	if(x > n) return true;
	for(int i = 1; i <= n; i++)
	{
		if(is_safe(i, x))
		{
			board[i][x] = true;
			if(f(x+1)) return true;
			board[i][x] = false;
		}
	}
	return false;
}

int main ()
{
	cin >> n;
	if(f(1))
	{
		cout << "YES" << endl;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				cout << (board[i][j] ? '1' : '0') << ' ';
			}
			cout << endl;
		}
	}
	else cout << "NO" << endl;
}

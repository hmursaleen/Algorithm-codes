#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, no_of_subset, subset_size;
	cin >> n;
	long long cnt, ans = 0;
	vector < long long > v(n);
	for(i = 0; i < n; i++)
	{
		cin >> v[i]; ///take input of the set
	}
	no_of_subset = 1 << n;
	for(i = 0; i < no_of_subset; i++)
	{
	    cnt = 0;
		vector < int > subset;
		for(j = 0; j < n; j++)
		{
			if(i & (1 << j))
            {
                cnt |= v[j];
				subset.push_back(v[j]);
            }
		}
		subset_size = subset.size();
		for(j = 0; j < subset_size; j++)
			cout << subset[j] << " "; /// printing a subset
		cout << "\n";
		///ans += cnt;
	}
	///cout << ans << endl;
}

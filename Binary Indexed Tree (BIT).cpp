#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200001
ll n, i, arr[M], BIT[M], l, r;
void upd(ll x, ll val)
{
   for(; x <= n; x += x & -x) BIT[x] += val; ///building the binary indexded tree
}

ll query(ll x)
{
   ll sum = 0;
   for(; x; x -= x & -x) sum += BIT[x];///getting the partial sum of [1,x]
   return sum;
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++)
   {
      cin >> arr[i];
      upd(i, arr[i]);
   }
   cin >> i; ///we want to know partial sum of [1,i];
   cout << query(i) << endl;
   ///as we have the partial sum, we can get the range sum of any range
   ///we can also make poll update, just using the upd function
   ///and the range sum of any range [l,r] = query(r) - query(l-1)
   ///let's see an example
   cin >> l >> r;
   cout << query(r) - query(l-1) << endl;
}

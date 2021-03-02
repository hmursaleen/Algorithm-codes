#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
#define M 1050
///we'll be using 0 based index here.
ll n, m, q, t, x, y, x2, y2, v, a[M][M], bit[M][M];
ll query(ll x, ll y)
{
   ll res = 0;
   if(x < 0 or y < 0) return 0; ///this is necessary, because any one of query(x-1, y2), query(x2, y-1), query(x-1, y-1) can lead to negative coordinates.
   for(ll i = x; i >= 0; i = (i & (i + 1)) - 1) ///as we're using 0 based index, so we can't use i -= i & -i here. this is how the loops should run while using 0 base index, learn it.
   for(ll j = y; j >= 0; j = (j & (j + 1)) - 1) res += bit[i][j];
   return res;
}

void upd(ll x, ll y, ll v)
{
   for(ll i = x; i < n; i = i | (i + 1)) ///as we're using 0 based index, so we can't use i += i & -i here. this is how it's supposed to be while using 0 based index in 2d array.
   for(ll j = y; j < m; j = j | (j + 1)) bit[i][j] += v;
}
/// note that, we didn't use loops like :
/// for(; x < n; x += x & -x) while upd, and also didn't use
/// for(; x >= 0; x -= x & -x). i mean, we didn't run our loops using x or y. we used i and j.
/// because, somehow, running loops using x and y in this case don't work
int main ()
{
   cin >> n >> m; ///n is no. of row and m is no. of column
   for(ll i = 0; i < n; i++) ///take input of initial 2d array
   {
      for(ll j = 0; j < m; j++)
      {
         cin >> a[i][j];
         upd(i, j, a[i][j]); ///update. all updates in this code are point update.
      }
   }
   cin >> q; /// no. of queries.
   while(q--)
   {
      cin >> t; ///the type of query. 1 is for upd, 2 is for query.
      if(t == 1) ///if it is an update
      {
         cin >> x >> y >> v; ///x,y is the coordinate where the upd will take place, and v is the value to add.
         ///v = v-a[x][y]; -> this applies when the upd operation is to set the value at x,y to v.
         upd(x, y, v);
      }
      else ///if it a query
      {
         cin >> x >> y >> x2 >> y2;
         cout << query(x2, y2) - query(x-1, y2) - query(x2, y-1) + query(x-1, y-1) << endl;
         ///yes, this is how we calculate sum in a rectangle enclosed by coordinates x, y, x2, y2
         ///where x <= x2 and y <= y2.
      }
   }
}

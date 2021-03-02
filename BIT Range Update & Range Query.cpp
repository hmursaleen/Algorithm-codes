#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
#define M 200005
///BIT range update and range query in one 1d array.

int n, q, i, l, r, v, t, a[M], bit1[M], bit2[M];
void add(int* bit, int x, int v)
{
   for(; x <= n; x += x & -x) bit[x] += v;
}

int query(int* bit, int x)
{
   int sum = 0;
   for(; x; x -= x & -x) sum += bit[x];
   return sum;
}

void range_add(int l, int r, int v)
{
   add(bit1, l, v);
   add(bit1, r+1, -v);
   add(bit2, l, v*(l-1));
   add(bit2, r+1, -v*r);
}

int prefix_sum(int x)
{
   return query(bit1, x) * x - query(bit2, x);
}

int range_query(int l, int r)
{
   return prefix_sum(r) - prefix_sum(l-1);
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++)
   {
      cin >> a[i];
      range_add(i, i, a[i]);
   }
   cin >> q;
   while(q--)
   {
      cin >> t >> l >> r;
      if(t == 1)
      {
         cin >> v;
         range_add(l, r, v);
      }
      else cout << range_query(l, r) << endl;
   }
}

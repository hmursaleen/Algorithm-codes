#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
pair < int, pair < int, int > > Q[200001]; ///using it store the queries.
int n, q, i, x, p[1000001], a[30001], bit[30005], ans[200001];

void upd(int x, int v)
{
   for(; x <= n; x += x & -x) bit[x] += v;
}

int query(int x)
{
   int sum = 0;
   for(; x; x -= x & -x) sum += bit[x];
   return sum;
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++) cin >> a[i];
   cin >> q;
   for(i = 0; i < q; i++) ///input of queries.
   {
      cin >> Q[i].ss.ff >> Q[i].ff; /// input of L, R respectively.
      ///we're storing R in Q[i].ff so that we can sort the queries easily as to R. (As data structures gets sorted according to the first element by default.)
      Q[i].ss.ss = i; ///storing the index of queries so that we can answer according the serial of queries.
   }
   sort(Q, Q + q);
   for(i = 1; i <= n; i++)
   {
      if(p[a[i]]) upd(p[a[i]], -1); ///if it appeared earlier, then undo its count.
      ///here array p stores index of last appearance of a[i].
      p[a[i]] = i; ///updating last appearance o a[i].
      upd(i, 1); ///update according to it.
      while(x < q and Q[x].ff == i) ///as long as more queries left and some query's R equals i
      {
         ans[Q[x].ss.ss] = query(Q[x].ff) - query(Q[x].ss.ff - 1); ///storing answer as query(r) - query(l-1)
         x++; ///continue traversing.
      }
   }
   for(i = 0; i < q; i++) printf("%d\n", ans[i]); ///printing answers.
}

///Author : Mursaleen
///Date :
///Problem topic : Disjoint Set Union (Practice)
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
#define M 200005
ll n, i, p[M], sz[M];

ll find_p(ll v)
{
   if(v == p[v]) return v;
   return p[v] = find_p(p[v]);
}

void unionn(ll a, ll b)
{
   a = find_p(a);
   b = find_p(b);
   if (a != b)
   {
      if(sz[a] < sz[b]) swap(a, b);
      p[b] = a; ///attaching the lower sized group with the higher sized group
      sz[a] += sz[b]; ///changing the size of higher sized group
   }
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
   ///here we'll be calculating size of each group because it'll be needed while
   ///merging two groups. why? because we'll attach the lower sized group with the
   ///higher sized group. why? because this way of merging two groups is faster.
   ///if we always attach the second group to the first group, or the first group
   ///to the second group, that can lead to groups containing chains of length O(n)
}
